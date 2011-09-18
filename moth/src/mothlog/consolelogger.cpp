/*
 * consolelogger.cpp
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <iostream>

#include <mothlog/consolelogger.h>
#include <moththread/thread.h>
#include <mothutil/mothexception.h>

namespace moth {

using namespace std;

ConsoleLogger::ConsoleLogger(string classname) : Logger(classname) {
}

ConsoleLogger::~ConsoleLogger() {
}

void ConsoleLogger::Error(string msg) {
    cout << DateTime() << " [" << Thread::CurrentThreadName() << "] ERROR " << classname << " - " << msg << endl;
}

void ConsoleLogger::Error(string msg, MothException e) {
    cout << DateTime() << " [" << Thread::CurrentThreadName() << "] ERROR " << classname << ":" << e.LineNumber() << " - " << msg << "(" << e.what() << ")" << endl;
}

void ConsoleLogger::Warn(string msg) {
    cout << DateTime() << " [" << Thread::CurrentThreadName() << "] WARN " << classname << " - " << msg << endl;
}

void ConsoleLogger::Warn(string msg, MothException e) {
    cout << DateTime() << " [" << Thread::CurrentThreadName() << "] WARN " << classname << ":" << e.LineNumber() << " - " << msg << "(" << e.what() << ")" << endl;
}

void ConsoleLogger::Debug(string msg) {
    cout << DateTime() << " [" << Thread::CurrentThreadName() << "] DEBUG " << classname << " - " << msg << endl;
}

void ConsoleLogger::Debug(string msg, MothException e) {
    cout << DateTime() << " [" << Thread::CurrentThreadName() << "] DEBUG " << classname << ":" << e.LineNumber() << " - " << msg << "(" << e.what() << ")" << endl;
}

void ConsoleLogger::Info(string msg) {
    cout << DateTime() << " [" << Thread::CurrentThreadName() << "] INFO " << classname << " - " << msg << endl;
}

void ConsoleLogger::Info(string msg, MothException e) {
    cout << DateTime() << " [" << Thread::CurrentThreadName() << "] INFO " << classname << ":" << e.LineNumber() << " - " << msg << "(" << e.what() << ")" << endl;
}

} /* namespace moth */
