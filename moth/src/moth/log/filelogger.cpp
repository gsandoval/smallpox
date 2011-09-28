/*
 * filelogger.cpp
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <moth/log/filelogger.h>
#include <moth/util/mothexception.h>

namespace moth {

using namespace std;

FileLogger::FileLogger(string classname) : Logger(classname) {

}

FileLogger::~FileLogger() {
}

void FileLogger::Write(string message) {
    cout << message << endl;
}

} /* namespace moth */
