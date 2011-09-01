/*
 * mothexception.h
 *
 *  Created on: 05/07/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef MOTHEXCEPTION_H_
#define MOTHEXCEPTION_H_

#include <exception>
#include <string>

namespace moth {

class MothException: public std::exception {
public:
    MothException(std::string message, int line_number);
    virtual ~MothException() throw();
    virtual const char* what() const throw();
    int LineNumber();
private:
    std::string message;
    int line_number;
};

} /* namespace moth */
#endif /* MOTHEXCEPTION_H_ */
