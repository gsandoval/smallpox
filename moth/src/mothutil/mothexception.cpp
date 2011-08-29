/*
 * MothException.cpp
 *
 *  Created on: 05/07/2011
 *      Author: darchitect
 */

#include <mothutil/mothexception.h>

namespace moth {

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
