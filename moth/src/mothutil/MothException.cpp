/*
 * MothException.cpp
 *
 *  Created on: 05/07/2011
 *      Author: darchitect
 */

#include <mothutil/MothException.h>

namespace moth {

MothException::MothException(string message, int lineNumber) : msg(message), line(lineNumber) {

}

MothException::~MothException() throw() {
}

const char* MothException::what() const throw() {
	return msg.c_str();
}

int MothException::lineNumber() {
	return line;
}

} /* namespace moth */
