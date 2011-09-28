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

LoggerFactory::LoggerFactory() {

}

LoggerFactory::~LoggerFactory() {
}

std::shared_ptr<Logger> LoggerFactory::CreateLogger(std::string classname) {
    return std::shared_ptr<Logger>(new ConsoleLogger(classname));
}

} /* namespace moth */
