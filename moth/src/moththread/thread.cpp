/*
 * Thread.cpp
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <moththread/thread.h>
#include <moththread/runnable.h>

namespace moth {

Thread::Thread() {
}

Thread::Thread(Runnable *r) : runnable(r) {

}

void Thread::Start() {
    /*
    std::thread t(Run, this);
    t.join();
    */
}

Thread::~Thread() {
    // TODO Auto-generated destructor stub
}

} /* namespace moth */
