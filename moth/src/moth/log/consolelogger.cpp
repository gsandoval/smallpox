/*
 * consolelogger.cpp
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <iostream>

#include <moth/log/consolelogger.h>
#include <moth/util/mothexception.h>

namespace moth {

using namespace std;

ConsoleLogger::ConsoleLogger(string classname) : Logger(classname) {
}

ConsoleLogger::~ConsoleLogger() {
}

void ConsoleLogger::Write(string message) {
    cout << message << endl;
}

} /* namespace moth */
