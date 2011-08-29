/*
 * Logger.h
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef CONSOLE_LOGGER_H_
#define CONSOLE_LOGGER_H_

#include <mothlog/logger.h>

namespace moth {

class ConsoleLogger : public Logger {
public:
    ConsoleLogger(string classname);
    virtual ~ConsoleLogger();
    virtual void Info(string msg);
    virtual void Info(string msg, MothException* e);
    virtual void Debug(string msg);
    virtual void Debug(string msg, MothException* e);
    virtual void Warn(string msg);
    virtual void Warn(string msg, MothException* e);
    virtual void Error(string msg);
    virtual void Error(string msg, MothException* e);
};

} /* namespace moth */
#endif /* CONSOLE_LOGGER_H_ */
