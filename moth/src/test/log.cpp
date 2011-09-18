/*
 * log.cpp
 *
 *  Created on: 05/07/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <mothlog/loggerfactory.h>

using namespace std;

int main(int argc, char* argv[]) {
    shared_ptr<moth::Logger> logger = moth::LoggerFactory::CreateLogger(__FILE__);
    logger->Error("Hello world");
    return 0;
}

