/*
 * filerollerlogger.cpp
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <mothlog/filerollerlogger.h>
#include <mothutil/mothexception.h>

namespace moth {

using namespace std;

FileRollerLogger::FileRollerLogger(string classname) : Logger(classname) {

}

FileRollerLogger::~FileRollerLogger() {
}

void FileRollerLogger::Error(string msg) {

}

void FileRollerLogger::Error(string msg, MothException e) {

}

void FileRollerLogger::Warn(string msg) {

}

void FileRollerLogger::Warn(string msg, MothException e) {

}

void FileRollerLogger::Debug(string msg) {

}

void FileRollerLogger::Debug(string msg, MothException e) {

}

void FileRollerLogger::Info(string msg) {

}

void FileRollerLogger::Info(string msg, MothException e) {

}

} /* namespace moth */
