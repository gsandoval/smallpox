/*
 * loggerfactory.cpp
 *
 *  Created on: 04/07/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <moth/log/loggerfactory.h>
#include <moth/log/consolelogger.h>
#include <moth/log/filelogger.h>
#include <moth/log/filerollerlogger.h>

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
