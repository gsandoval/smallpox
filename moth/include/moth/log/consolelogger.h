/*
 * consolelogger.h
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef CONSOLE_LOGGER_H_
#define CONSOLE_LOGGER_H_

#include <moth/log/logger.h>

namespace moth {

class ConsoleLogger : public Logger {
public:
    ConsoleLogger(std::string classname);
    virtual ~ConsoleLogger();
    virtual void Info(std::string msg);
    virtual void Info(std::string msg, MothException e);
    virtual void Debug(std::string msg);
    virtual void Debug(std::string msg, MothException e);
    virtual void Warn(std::string msg);
    virtual void Warn(std::string msg, MothException e);
    virtual void Error(std::string msg);
    virtual void Error(std::string msg, MothException e);
};

} /* namespace moth */
#endif /* CONSOLE_LOGGER_H_ */
