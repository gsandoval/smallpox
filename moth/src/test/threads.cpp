/*
 * threads.cpp
 *
 *  Created on: 31/08/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <iostream>
#include <memory>

#include <moththread/thread.h>
#include <moththread/threadpool.h>
#include <moththread/runnable.h>
#include <mothlog/loggerfactory.h>

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
    //run_local_thread();
    shared_ptr<moth::Logger> logger = moth::LoggerFactory::CreateLogger(__FILE__);
    logger->Debug("Hi there");
    shared_ptr<moth::ThreadPool> pool = moth::ThreadPoolBuilder::BuildThreadPool(4);
    for (int i = 0; i < 50; ++i) {
        pool->Execute([]() {
                      shared_ptr<moth::Logger> LOG = moth::LoggerFactory::CreateLogger(__FILE__);
                LOG->Debug("Hello");
                      for(int i = 0; i < 1000; ++i)for(int j = 0; j < 1000000; ++j);
        });
    }
    //pool->Shutdown();
    string r;
    cin >> r;
    return 0;
}
