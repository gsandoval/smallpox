/*
 * Logger.cpp
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <mothlog/FileLogger.h>

namespace moth {

FileLogger::FileLogger(string _className) : className(_className) {

}

FileLogger::~FileLogger() {
}

void FileLogger::error(string msg) {

}

void FileLogger::error(string msg, MothException& e) {

}

void FileLogger::warn(string msg) {

}

void FileLogger::warn(string msg, MothException& e) {

}

void FileLogger::debug(string msg) {

}

void FileLogger::debug(string msg, MothException& e) {

}

void FileLogger::info(string msg) {

}

void FileLogger::info(string msg, MothException& e) {

}

} /* namespace moth */
