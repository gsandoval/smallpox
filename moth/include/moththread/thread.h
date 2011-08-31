/*
 * Thread.h
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef THREAD_H_
#define THREAD_H_

#include <memory>
#include <string>
#include <pthread.h>

#include <moththread/runnable.h>
#include <moththread/mutex.h>

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
    Thread(std::shared_ptr<Runnable> runnable);
    Thread(void (*run_function)(void));
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

private:
    std::shared_ptr<Runnable> runnable;
    pthread_t tid;
    std::string thread_name;
    ThreadState state;
    Mutex state_mutex;
    void (*run_function_ptr)(void);
    friend void* run_wrapper(void*);

    /*!
      * This method must not be called by anyone. I'll say it again, this method
      * must not be called by anyone.
      * @see State
      * @param state The new state of the thread
      */
    void SetState(ThreadState state);
};

} /* namespace moth */
#endif /* THREAD_H_ */
