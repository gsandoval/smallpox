/*
 * Logger.h
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>

namespace moth {

class MothException;

class Logger {
public:
    Logger(std::string classname);
    virtual ~Logger();
    virtual void Info(std::string msg) = 0;
    virtual void Info(std::string msg, MothException* e) = 0;
    virtual void Debug(std::string msg) = 0;
    virtual void Debug(std::string msg, MothException* e) = 0;
    virtual void Warn(std::string msg) = 0;
    virtual void Warn(std::string msg, MothException* e) = 0;
    virtual void Error(std::string msg) = 0;
    virtual void Error(std::string msg, MothException* e) = 0;
protected:
    std::string classname;

    virtual std::string DateTime();
};

} /* namespace moth */
#endif /* LOGGER_H_ */
