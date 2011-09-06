/*
 * threadpool.h
 *
 *  Created on: 01/09/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <memory>
#include <vector>

#include <moththread/runnable.h>
#include <moththread/thread.h>
#include <moththread/mutex.h>
#include <mothutil/mothexception.h>

namespace moth {

class ThreadPool : public Thread {
private:
    class Worker : public Runnable {
    public:
        enum WorkerState { Busy, Available };

        Worker(ThreadPool *pool);
        ~Worker();
        void SetTask(std::shared_ptr<Runnable> task);
        void SetTask(void (*function_task)(void));
        void Run();
        void ScheduleToStop();
        WorkerState State();
    private:
        std::shared_ptr<Runnable> task;
        void (*function_task)(void);
        Mutex task_mutex;
        bool running;
        ThreadPool *pool;
        WorkerState state;
    };

public:
    struct TaskPayload {
        void (*function_task)(void);
        std::shared_ptr<Runnable> task;
    };

    static const int MAX_TASK_PRIORITY;

    virtual ~ThreadPool();
    void Run();
    void Execute(std::shared_ptr<Runnable> task);
    void Execute(std::shared_ptr<Runnable> task, int priority);
    void Execute(void (*function_task)(void));
    void Execute(void (*function_task)(void), int priority);
    //void Call(std::shared_ptr<Callable> callable);
private:
    std::vector<std::shared_ptr<Thread> > threads;
    int max_thread_count;
    long long max_idle_time;
    int core_threads;
    Mutex threads_lock;
    std::vector<TaskPayload> task_queue[];
    Mutex task_queue_mutex;
    bool alive;
    int available_threads;
    int queued_tasks;
    friend class ThreadPoolBuilder;

    ThreadPool();
    ThreadPool(int max_thread_count);
    ThreadPool(int max_thread_count, int max_idle_time, int core_threads);
    TaskPayload PollTask();
    void RunTask(std::shared_ptr<Worker> w, TaskPayload tp);
    void BeforeExecute(std::shared_ptr<Runnable> task);
    void BeforeExecute(void (*function_task)(void));
    void AfterExecute(std::shared_ptr<Runnable> task);
    void AfterExecute(std::shared_ptr<Runnable> task, MothException e);
    void AfterExecute(void (*function_task)(void));
    void AfterExecute(void (*function_task)(void), MothException e);
};

const int ThreadPool::MAX_TASK_PRIORITY = 10;
std::vector<ThreadPool::TaskPayload> task_queue[ThreadPool::MAX_TASK_PRIORITY];

class ThreadPoolBuilder {
public:
    static std::shared_ptr<ThreadPool> BuildThreadPool();
    static std::shared_ptr<ThreadPool> BuildThreadPool(int max_thread_count);
    static std::shared_ptr<ThreadPool> BuildThreadPool(int max_thread_count,
                                                       int max_idle_time,
                                                       int core_threads);
};

} /* namespace moth */

#endif // THREADPOOL_H
