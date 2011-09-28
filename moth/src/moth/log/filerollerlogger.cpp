/*
 * filerollerlogger.cpp
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <moth/log/filerollerlogger.h>
#include <moth/util/mothexception.h>

namespace moth {

using namespace std;

FileRollerLogger::FileRollerLogger(string classname) : Logger(classname) {

}

FileRollerLogger::~FileRollerLogger() {
}

void FileRollerLogger::Write(string message) {
    cout << message << endl;
}

} /* namespace moth */
