/*
 * Thread.cpp
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <pthread.h>
#include <cstdlib>
#include <utility>
#include <iostream>

#include <moththread/thread.h>
#include <moththread/runnable.h>

namespace moth {

using namespace std;

Thread::Thread() : state(Thread::NotRunning) {
}

Thread::Thread(void (*run_function)(void)) : state(Thread::NotRunning) {

}

Thread::Thread(shared_ptr<Runnable> r) : runnable(r), state(Thread::NotRunning) {

}

void Thread::SetName(std::string thread_name) {
    this->thread_name = thread_name;
}

string Thread::Name() {
    return thread_name;
}

void* run_wrapper(void* param) {
    pair<Thread*, shared_ptr<Runnable>> *paramPair = (pair<Thread*, shared_ptr<Runnable>> *) param;
    Thread *t = paramPair->first;
    shared_ptr<Runnable> r = paramPair->second;
    t->SetState(Thread::Started);
    if (r) {
        r->Run();
    } else {
        t->Run();
    }
    t->SetState(Thread::Stopped);
    delete paramPair;
    return 0;
}

void Thread::Run() {
    cout << "thread run" << endl;
}

void Thread::Join() {
    pthread_join(tid, NULL);
}

void Thread::Start() {
    pair<Thread*, shared_ptr<Runnable>> *param = new pair<Thread*, shared_ptr<Runnable>>;
    param->first = this;
    if (runnable) {
        param->second = runnable;
    } else {
        /*
        cout << "before" << endl;
        param->second = shared_ptr<Runnable>(this);
        cout << "after" << endl;
        */
    }
    pthread_create(&tid, NULL, run_wrapper, param);
}

Thread::~Thread() {
    state_mutex.Lock();
    while (state == Started) {
        state_mutex.Wait(200);
    }
    state_mutex.Unlock();
    cout << "thread dtor" << endl;
}

void Thread::SetState(Thread::ThreadState state) {
    state_mutex.Lock();
    this->state = state;
    state_mutex.Notify();
    state_mutex.Unlock();
}

Thread::ThreadState Thread::State() {
    state_mutex.Lock();
    ThreadState c = state;
    state_mutex.Unlock();
    return c;
}

} /* namespace moth */