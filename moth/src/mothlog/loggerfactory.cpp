/*
 * loggerfactory.cpp
 *
 *  Created on: 04/07/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <mothlog/loggerfactory.h>
#include <mothlog/consolelogger.h>
#include <mothlog/filelogger.h>
#include <mothlog/filerollerlogger.h>

namespace moth {

using namespace std;

LoggerFactory::LoggerFactory() {

}

LoggerFactory::~LoggerFactory() {
}

shared_ptr<Logger> LoggerFactory::CreateLogger(string classname) {
    return shared_ptr<Logger>(new ConsoleLogger(classname));
}

} /* namespace moth */
