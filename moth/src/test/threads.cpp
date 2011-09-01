/*
 * threads.cpp
 *
 *  Created on: 31/08/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <iostream>
#include <memory>

#include <moththread/thread.h>
#include <moththread/runnable.h>

using namespace std;

class RunnableImpl : public moth::Runnable {
public:
    void Run() {
        cout << "impl started" << endl;
        for (int i = 0; i < 2000000; ++i)
            if (i % 1000 == 0)
                ;
        cout << "impl ended" << endl;
    }
    ~RunnableImpl() {
        cout << "impl dtor" << endl;
    }
};

void run_local_thread() {
    //shared_ptr<moth::Runnable> runnable(new RunnableImpl);
    //  //moth::Thread t(runnable);
    //t.Start();
    //moth::Thread t2([](){ cout << "wordked!!!!" << endl; });
    moth::Thread *t2 = new moth::Thread([](){ cout << "wordked!!!!" << endl; });
    t2->Start();
    //moth::Thread t3;
    //t3.Join();
}

int main(int argc, char* argv[]) {
    run_local_thread();
    string r;
    cin >> r;
    return 0;
}
