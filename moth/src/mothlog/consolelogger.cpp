/*
 * Logger.cpp
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <iostream>

#include <mothlog/consolelogger.h>
#include <mothutil/mothexception.h>

namespace moth {

ConsoleLogger::ConsoleLogger(string classname) : Logger(classname) {
}

ConsoleLogger::~ConsoleLogger() {
}

void ConsoleLogger::Error(string msg) {
    cout << DateTime() << " [main] ERROR " << classname << " - " << msg << endl;
}

void ConsoleLogger::Error(string msg, MothException* e) {
    cout << DateTime() << " [main] ERROR " << classname << ":" << e->LineNumber() << " - " << msg << "(" << e->what() << ")" << endl;
}

void ConsoleLogger::Warn(string msg) {
    cout << DateTime() << " [main] WARN " << classname << " - " << msg << endl;
}

void ConsoleLogger::Warn(string msg, MothException* e) {
    cout << DateTime() << " [main] WARN " << classname << ":" << e->LineNumber() << " - " << msg << "(" << e->what() << ")" << endl;
}

void ConsoleLogger::Debug(string msg) {
    cout << DateTime() << " [main] DEBUG " << classname << " - " << msg << endl;
}

void ConsoleLogger::Debug(string msg, MothException* e) {
    cout << DateTime() << " [main] DEBUG " << classname << ":" << e->LineNumber() << " - " << msg << "(" << e->what() << ")" << endl;
}

void ConsoleLogger::Info(string msg) {
    cout << DateTime() << " [main] INFO " << classname << " - " << msg << endl;
}

void ConsoleLogger::Info(string msg, MothException* e) {
    cout << DateTime() << " [main] INFO " << classname << ":" << e->LineNumber() << " - " << msg << "(" << e->what() << ")" << endl;
}

} /* namespace moth */
