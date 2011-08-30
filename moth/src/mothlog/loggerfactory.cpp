/*
 * LoggerFactory.cpp
 *
 *  Created on: 04/07/2011
 *      Author: darchitect
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

Logger* LoggerFactory::CreateLogger(string classname) {
    return new ConsoleLogger(classname);
}

} /* namespace moth */
