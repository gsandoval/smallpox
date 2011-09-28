/*
 * filelogger.h
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef FILE_LOGGER_H_
#define FILE_LOGGER_H_

#include <string>

#include <moth/log/logger.h>

namespace moth {

class FileLogger : public Logger {
public:
    FileLogger(std::string classname);
    virtual ~FileLogger();
    virtual void Write(std::string message);
};

} /* namespace moth */
#endif /* FILE_LOGGER_H_ */
