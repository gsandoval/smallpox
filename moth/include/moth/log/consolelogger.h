/*
 * consolelogger.h
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef CONSOLE_LOGGER_H_
#define CONSOLE_LOGGER_H_

#include <string>

#include <moth/log/logger.h>

namespace moth {

class ConsoleLogger : public Logger {
public:
    ConsoleLogger(std::string classname);
    virtual ~ConsoleLogger();
    virtual void Write(std::string message);
};

} /* namespace moth */
#endif /* CONSOLE_LOGGER_H_ */
