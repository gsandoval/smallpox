/*
 * Thread.h
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef THREAD_H_
#define THREAD_H_

#include <memory>

namespace moth {

class Runnable;

class Thread {
public:
    Thread();
    Thread(Runnable *runnable);
    virtual ~Thread();
    void Start();

protected:
    virtual void Run() = 0;

private:
    std::shared_ptr<Runnable> runnable;
};

} /* namespace moth */
#endif /* THREAD_H_ */
