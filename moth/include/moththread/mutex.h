/*
 * mutex.h
 *
 *  Created on: 31/08/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef MUTEX_H
#define MUTEX_H

#include <pthread.h>

namespace moth {

class Mutex {
public:
    Mutex();
    virtual ~Mutex();
    bool TryLock();
    void Lock();
    void Unlock();
    bool Wait(long long timeout);
    void Wait();
    void Notify();
    void NotifyAll();
private:
    pthread_mutex_t mutex;
    pthread_cond_t condition;
};

} /* namespace moth */

#endif // MUTEX_H
