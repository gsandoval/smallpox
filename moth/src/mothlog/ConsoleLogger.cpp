/*
 * Logger.cpp
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <mothlog/ConsoleLogger.h>

namespace moth {

ConsoleLogger::ConsoleLogger(string _className) : className(_className) {

}

ConsoleLogger::~ConsoleLogger() {
}

void ConsoleLogger::error(string msg) {

}

void ConsoleLogger::error(string msg, MothException& e) {

}

void ConsoleLogger::warn(string msg) {

}

void ConsoleLogger::warn(string msg, MothException& e) {

}

void ConsoleLogger::debug(string msg) {

}

void ConsoleLogger::debug(string msg, MothException& e) {

}

void ConsoleLogger::info(string msg) {

}

void ConsoleLogger::info(string msg, MothException& e) {

}

} /* namespace moth */
