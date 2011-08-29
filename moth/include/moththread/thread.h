/*
 * Thread.h
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef THREAD_H_
#define THREAD_H_

namespace moth {

class Runnable;

class Thread {
public:
	Thread();
	Thread(Runnable *runnable);
	virtual ~Thread();
	void Start();

protected:
	virtual void Run();

private:
	Runnable* runnable;
};

} /* namespace moth */
#endif /* THREAD_H_ */
