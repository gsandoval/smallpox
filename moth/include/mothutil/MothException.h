/*
 * MothException.h
 *
 *  Created on: 05/07/2011
 *      Author: darchitect
 */

#ifndef MOTHEXCEPTION_H_
#define MOTHEXCEPTION_H_

#include <exception>

#include <string>

using namespace std;

namespace moth {

class MothException: public std::exception {
public:
	MothException(string message, int lineNumber);
	virtual ~MothException() throw();
	virtual const char* what() const throw();
	int lineNumber();
private:
	string msg;
	int line;
};

} /* namespace moth */
#endif /* MOTHEXCEPTION_H_ */
