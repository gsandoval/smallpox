/*
 * threadpool.cpp
 *
 *  Created on: 01/09/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <cstdlib>
#include <algorithm>
#include <memory>

#include <moththread/threadpool.h>

namespace moth {

using namespace std;

shared_ptr<ThreadPool> ThreadPoolBuilder::BuildThreadPool() {
    auto tp = shared_ptr<ThreadPool>(new ThreadPool);
    tp->Start();
    return tp;
}

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

ThreadPool::Worker::Worker(ThreadPool *_pool) : running(false), pool(_pool),
    state(Worker::Available) {
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
        } else {
            task_mutex.Lock();
            state = Available;
            task_mutex.Wait();
            task_mutex.Unlock();
        }
    }
}

ThreadPool::Worker::WorkerState ThreadPool::Worker::State() {
    return state;
}

void ThreadPool::Worker::ScheduleToStop() {
    running = false;
    task_mutex.Lock();
    task_mutex.Notify();
    task_mutex.Unlock();
}

ThreadPool::ThreadPool() : available_threads(0), queued_tasks(0) {
}

ThreadPool::ThreadPool(int thread_count) : max_thread_count(thread_count), max_idle_time(-1),
    core_threads(0), available_threads(0), queued_tasks(0) {
}

ThreadPool::ThreadPool(int thread_count, int idle_time, int _core_threads) : max_thread_count(thread_count),
    max_idle_time(idle_time), core_threads(_core_threads), available_threads(_core_threads), queued_tasks(0) {
    threads_lock.Lock();
    for (int i = 0; i < core_threads; ++i) {
        shared_ptr<Thread> t(new Thread(shared_ptr<Runnable>(new Worker(this))));
        threads.push_back(t);
        t->Start();
    }
    threads_lock.Unlock();
}

void ThreadPool::Run() {
    alive = true;
    while (alive) {
        task_queue_mutex.Lock();
        if (queued_tasks <= 0) {
            task_queue_mutex.Wait();
        }
        task_queue_mutex.Unlock();

        threads_lock.Lock();
        if (available_threads > 0) {
            for (auto it = threads.begin(); it != threads.end(); ++it) {
                shared_ptr<Worker> w = dynamic_pointer_cast<Worker>((*it)->InnerRunnable());
                if (w->State() == ThreadPool::Worker::Available) {
                    TaskPayload tp = PollTask();
                    RunTask(w, tp);
                }
            }
        } else if (static_cast<int>(threads.size()) < max_thread_count) {
            shared_ptr<Thread> t(new Thread(shared_ptr<Runnable>(new Worker(this))));
            threads.push_back(t);
            t->Start();
            shared_ptr<Worker> w = dynamic_pointer_cast<Worker>(t->InnerRunnable());
            TaskPayload tp = PollTask();
            RunTask(w, tp);
        }
        threads_lock.Unlock();
    }
}

void ThreadPool::RunTask(shared_ptr<Worker> w, TaskPayload tp) {
    if (tp.function_task) {
        w->SetTask(tp.function_task);
    } else if (tp.task) {
        w->SetTask(tp.task);
    }
}

ThreadPool::TaskPayload ThreadPool::PollTask() {
    TaskPayload tp{ NULL };
    task_queue_mutex.Lock();
    for (int i = MAX_TASK_PRIORITY; i >= 0; --i) {
        if (task_queue[i].size() > 0) {
            tp = *task_queue[i].erase(task_queue[i].begin());
            queued_tasks--;
            break;
        }
    }
    task_queue_mutex.Unlock();
    return tp;
}

ThreadPool::~ThreadPool() {
    // TODO wait until all threads have stopped
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
    task_queue[priority].push_back(TaskPayload{ NULL, task });
    queued_tasks++;
    task_queue_mutex.Notify();
    task_queue_mutex.Unlock();
}

void ThreadPool::Execute(void (*function_task)(void), int priority) {
    priority = max(priority, 0);
    priority = min(priority, MAX_TASK_PRIORITY);
    task_queue_mutex.Lock();
    task_queue[priority].push_back(TaskPayload{ function_task });
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
