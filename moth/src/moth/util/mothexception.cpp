/*
 * mothexception.cpp
 *
 *  Created on: 05/07/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <moth/util/mothexception.h>

namespace moth {

using namespace std;

MothException::MothException(string _message, int _line_number) : message(_message), line_number(_line_number) {

}

MothException::~MothException() throw() {
}

const char* MothException::what() const throw() {
    return message.c_str();
}

int MothException::LineNumber() {
    return line_number;
}

} /* namespace moth */
