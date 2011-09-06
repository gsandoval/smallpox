/*
 * mutex.cpp
 *
 *  Created on: 31/08/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <ctime>
#include <cstdlib>

#include <moththread/mutex.h>

namespace moth {

Mutex::Mutex() : mutex(PTHREAD_MUTEX_INITIALIZER),
    condition(PTHREAD_COND_INITIALIZER) {
}

Mutex::~Mutex() {
}

bool Mutex::TryLock() {
    return pthread_mutex_trylock(&mutex) == 0;
}

void Mutex::Lock() {
    pthread_mutex_lock(&mutex);
}

void Mutex::Unlock() {
    pthread_mutex_unlock(&mutex);
}

void Mutex::Wait(long long timeout) {
    timespec ts;
    ts.tv_sec = time(NULL) + timeout / 1000;
    ts.tv_nsec = (timeout % 1000) * 1000 * 1000;
    pthread_cond_timedwait(&condition, &mutex, &ts);
}

void Mutex::Wait() {
    pthread_cond_wait(&condition, &mutex);
}

void Mutex::Notify() {
    pthread_cond_signal(&condition);
}

void Mutex::NotifyAll() {
    pthread_cond_broadcast(&condition);
}

} /* namespace moth */

