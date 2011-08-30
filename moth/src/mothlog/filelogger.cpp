/*
 * Logger.cpp
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <mothlog/filelogger.h>
#include <mothutil/mothexception.h>

namespace moth {

using namespace std;

FileLogger::FileLogger(string classname) : Logger(classname) {

}

FileLogger::~FileLogger() {
}

void FileLogger::Error(string msg) {

}

void FileLogger::Error(string msg, MothException* e) {

}

void FileLogger::Warn(string msg) {

}

void FileLogger::Warn(string msg, MothException* e) {

}

void FileLogger::Debug(string msg) {

}

void FileLogger::Debug(string msg, MothException* e) {

}

void FileLogger::Info(string msg) {

}

void FileLogger::Info(string msg, MothException* e) {

}

} /* namespace moth */
