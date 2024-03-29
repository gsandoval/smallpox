/*
 * thread.h
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef THREAD_H_
#define THREAD_H_

#include <memory>
#include <string>
#include <pthread.h>

#include <moth/thread/runnable.h>
#include <moth/thread/mutex.h>
#include <moth/thread/threadlocal.h>

namespace moth {

void* run_wrapper(void*);

/*! \class Thread
  * \brief A Thread abstraction
  *
  * This class provides the basic abstraction of a thread. The user should
  * implement either the Thread's Run method or the Runnable's Run method.
  */
class Thread : public Runnable {
public:
    /*! \enum ThreadState
      * \brief All Thread states
      *
      * Lists all the possible thread states.
      */
    enum ThreadState { NotRunning, Started, Stopped, Deleted };

    Thread();
    Thread(std::string thread_name);
    Thread(std::shared_ptr<Runnable> runnable);
    Thread(std::shared_ptr<Runnable> runnable, std::string thread_name);
    Thread(void (*run_function)(void));
    Thread(void (*run_function)(void), std::string thread_name);
    virtual ~Thread();
    void Start();
    virtual void Run();
    void Join();
    void SetName(std::string thread_name);
    std::string Name();
    /*!
      * This method return the current state of the thread.
      * @see Thread::ThreadState
      * @return The current state of the thread
      */
    ThreadState State();
    static std::string CurrentThreadName();
    static Thread* CurrentThread();

private:
    std::shared_ptr<Runnable> runnable;
    pthread_t tid;
    std::string unsafe_thread_name;
    ThreadState state;
    Mutex state_mutex;
    void (*run_function_ptr)(void);
    friend void* run_wrapper(void*);
    friend class ThreadPool;
    static void SetCurrentThread(Thread *t);

    void SetState(ThreadState state);
    /*!
      * This method should only be called from the threadpool impl
      * and allows it to get a reference to the inner worker
      */
    std::shared_ptr<Runnable> InnerRunnable();
};

} /* namespace moth */
#endif /* THREAD_H_ */
