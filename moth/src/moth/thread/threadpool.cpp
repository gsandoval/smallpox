/*
 * threadpool.cpp
 *
 *  Created on: 01/09/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <cstdlib>
#include <algorithm>
#include <memory>
#include <sstream>
#include <iostream>

#include <moth/thread/threadpool.h>
#include <moth/util/clock.h>

namespace moth {

using namespace std;

shared_ptr<ThreadPool> ThreadPoolBuilder::BuildThreadPool(
    int max_thread_count) {
    auto tp = shared_ptr<ThreadPool>(new ThreadPool(max_thread_count));
    tp->Start();
    return tp;
}

shared_ptr<ThreadPool> ThreadPoolBuilder::BuildThreadPool(
    int max_thread_count, int max_idle_time, int core_threads) {
    auto tp = shared_ptr<ThreadPool>(new ThreadPool(max_thread_count, max_idle_time, core_threads));
    tp->Start();
    return tp;
}

ThreadPool::Worker::Worker(ThreadPool *_pool, long long _max_idle_time) : max_idle_time(_max_idle_time),
    running(false), pool(_pool), state(Worker::Available) {
    function_task = NULL;
}

ThreadPool::Worker::~Worker() {

}

void ThreadPool::Worker::SetTask(std::shared_ptr<Runnable> task) {
    state = Busy;
    task_mutex.Lock();
    this->task = task;
    task_mutex.Notify();
    task_mutex.Unlock();
}

void ThreadPool::Worker::SetTask(void (*function_task)(void)) {
    state = Busy;
    task_mutex.Lock();
    this->function_task = function_task;
    task_mutex.Notify();
    task_mutex.Unlock();
}

void ThreadPool::Worker::Run() {
    running = true;
    while (running) {
        if (task || function_task) {
            if (task) {
                pool->BeforeExecute(task);
                try {
                    task->Run();
                    pool->AfterExecute(task);
                } catch (MothException &e) {
                    pool->AfterExecute(task, e);
                }
                task.reset();
            } else if (function_task) {
                pool->BeforeExecute(function_task);
                try {
                    function_task();
                    pool->AfterExecute(function_task);
                } catch (MothException &e) {
                    pool->AfterExecute(function_task, e);
                }
                function_task = NULL;
            }
            task_mutex.Lock();
            last_scheduled_task = Clock::CurrentTime();
            state = Available;
            task_mutex.Unlock();

            pool->ReleaseThread();

            WaitForTask();
        } else {
            WaitForTask();
        }
    }
    state = Stopped;
}

void ThreadPool::Worker::WaitForTask() {
    task_mutex.Lock();
    if (running && !(task || function_task)) {
        task_mutex.Wait();
    }
    task_mutex.Unlock();
}

bool ThreadPool::Worker::IsExpired() {
    return (state == ThreadPool::Worker::Available) && (Clock::CurrentTime() - last_scheduled_task > max_idle_time);
}

ThreadPool::Worker::WorkerState ThreadPool::Worker::State() {
    return state;
}

void ThreadPool::Worker::ScheduleToStop() {
    task_mutex.Lock();
    running = false;
    task_mutex.Notify();
    task_mutex.Unlock();
}

ThreadPool::ThreadPool(int thread_count) : Thread("ThreadPool"), max_thread_count(thread_count), max_idle_time(-1),
    core_threads(0), available_threads(0), queued_tasks(0) {
    for (int i = 0; i <= MAX_TASK_PRIORITY; ++i) {
        task_queue.push_back(vector<shared_ptr<TaskPayload> >());
    }
}

ThreadPool::ThreadPool(int thread_count, int idle_time, int _core_threads) : Thread("ThreadPool"),
    max_thread_count(thread_count), max_idle_time(idle_time), core_threads(_core_threads), available_threads(0),
    queued_tasks(0) {
    for (int i = 0; i <= MAX_TASK_PRIORITY; ++i) {
        task_queue.push_back(vector<shared_ptr<TaskPayload> >());
    }
    threads_lock.Lock();
    for (int i = 0; i < core_threads; ++i) {
        CreateWorker();
    }
    threads_lock.Unlock();
}

shared_ptr<ThreadPool::Worker> ThreadPool::CreateWorker() {
    available_threads++;
    static int worker_counter = 0;
    ostringstream oss;
    oss << "ThreadPool::Worker-" << ++worker_counter;
    string worker_name = oss.str();
    shared_ptr<Thread> t(new Thread(shared_ptr<Runnable>(new Worker(this, max_idle_time)), worker_name));
    t->Start();
    threads.push_back(t);
    shared_ptr<Worker> w = dynamic_pointer_cast<Worker>(t->InnerRunnable());
    return w;
}

void ThreadPool::PurgeWorkers() {
    threads_lock.Lock();
    threads.erase(remove_if(threads.begin(), threads.end(),
        [](shared_ptr<Thread> t) { return dynamic_pointer_cast<Worker>(t->InnerRunnable())->IsExpired(); }
    ), threads.end());
    threads_lock.Unlock();
}

void ThreadPool::ReleaseThread() {
    threads_lock.Lock();
    available_threads++;
    threads_lock.Notify();
    threads_lock.Unlock();
}

ThreadPool::~ThreadPool() {
    Shutdown();
}

void ThreadPool::Shutdown() {
    if (!alive) {
        return;
    }

    alive = false;

    task_queue_mutex.Lock();
    task_queue_mutex.Notify();
    task_queue_mutex.Unlock();

    threads_lock.Lock();
    for (auto it = threads.begin(); it != threads.end(); ++it) {
        shared_ptr<Worker> w = dynamic_pointer_cast<Worker>((*it)->InnerRunnable());
        w->ScheduleToStop();
    }
    threads_lock.Notify();
    threads_lock.Unlock();
}

void ThreadPool::Run() {
    alive = true;
    while (alive) {
        task_queue_mutex.Lock();
        if (queued_tasks <= 0 && alive /* Race condition aware */) {
            if (max_idle_time == -1) {
                task_queue_mutex.Wait();
            } else {
                bool signaled = task_queue_mutex.Wait(max_idle_time);
                if (!signaled) {
                    PurgeWorkers();
                    continue;
                }
            }
        }
        task_queue_mutex.Unlock();

        if (!alive) {
            continue;
        }

        threads_lock.Lock();
        if (available_threads == 0 && static_cast<int>(threads.size()) == max_thread_count && alive /* Race condition aware */) {
            threads_lock.Wait();
        }

        if (available_threads > 0 && alive /* Race condition aware */) {
            for (auto it = threads.begin(); it != threads.end(); ++it) {
                shared_ptr<Worker> w = dynamic_pointer_cast<Worker>((*it)->InnerRunnable());
                if (w->State() == ThreadPool::Worker::Available) {
                    shared_ptr<TaskPayload> tp = PollTask();
                    if (tp) {
                        RunTask(w, tp);
                    }
                }
            }
        } else if (static_cast<int>(threads.size()) < max_thread_count && alive /* Race condition aware */) {
            shared_ptr<TaskPayload> tp = PollTask();
            if (tp) {
                shared_ptr<Worker> w = CreateWorker();
                RunTask(w, tp);
            }
        }
        threads_lock.Unlock();
    }
}

void ThreadPool::RunTask(shared_ptr<Worker> w, shared_ptr<TaskPayload> tp) {
    available_threads--;

    if (tp->function_task) {
        w->SetTask(tp->function_task);
    } else if (tp->task) {
        w->SetTask(tp->task);
    }
}

shared_ptr<ThreadPool::TaskPayload> ThreadPool::PollTask() {
    shared_ptr<TaskPayload> tp;
    task_queue_mutex.Lock();
    for (int i = MAX_TASK_PRIORITY; i >= 0; --i) {
        if (task_queue[i].size() > 0) {
            tp = *(task_queue[i].begin());
            pop_heap(task_queue[i].begin(), task_queue[i].end());
            queued_tasks--;
            break;
        }
    }
    task_queue_mutex.Unlock();
    return tp;
}

void ThreadPool::Execute(shared_ptr<Runnable> task) {
    Execute(task, 5);
}

void ThreadPool::Execute(void (*function_task)(void)) {
    Execute(function_task, 5);
}

void ThreadPool::Execute(shared_ptr<Runnable> task, int priority) {
    priority = max(priority, 0);
    priority = min(priority, MAX_TASK_PRIORITY);
    task_queue_mutex.Lock();
    shared_ptr<TaskPayload> tp(new TaskPayload);
    tp->task = task;
    tp->function_task = NULL;
    task_queue[priority].push_back(tp);
    queued_tasks++;
    task_queue_mutex.Notify();
    task_queue_mutex.Unlock();
}

void ThreadPool::Execute(void (*function_task)(void), int priority) {
    priority = max(priority, 0);
    priority = min(priority, MAX_TASK_PRIORITY);
    task_queue_mutex.Lock();
    shared_ptr<TaskPayload> tp(new TaskPayload);
    tp->function_task = function_task;
    task_queue[priority].push_back(tp);
    queued_tasks++;
    task_queue_mutex.Notify();
    task_queue_mutex.Unlock();
}

void ThreadPool::BeforeExecute(shared_ptr<Runnable> task) {

}

void ThreadPool::BeforeExecute(void (*function_task)(void)) {

}

void ThreadPool::AfterExecute(shared_ptr<Runnable> task) {

}

void ThreadPool::AfterExecute(shared_ptr<Runnable> task, MothException e) {

}

void ThreadPool::AfterExecute(void (*function_task)(void)) {

}

void ThreadPool::AfterExecute(void (*function_task)(void), MothException e) {

}

}
