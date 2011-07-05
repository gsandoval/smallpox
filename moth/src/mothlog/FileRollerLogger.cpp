/*
 * Logger.cpp
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <mothlog/FileRollerLogger.h>

namespace moth {

FileRollerLogger::FileRollerLogger(string _className) : className(_className) {

}

FileRollerLogger::~FileRollerLogger() {
}

void FileRollerLogger::error(string msg) {

}

void FileRollerLogger::error(string msg, MothException& e) {

}

void FileRollerLogger::warn(string msg) {

}

void FileRollerLogger::warn(string msg, MothException& e) {

}

void FileRollerLogger::debug(string msg) {

}

void FileRollerLogger::debug(string msg, MothException& e) {

}

void FileRollerLogger::info(string msg) {

}

void FileRollerLogger::info(string msg, MothException& e) {

}

} /* namespace moth */
