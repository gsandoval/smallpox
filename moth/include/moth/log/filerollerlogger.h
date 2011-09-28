/*
 * filerollerlogger.h
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef FILE_ROLLER_LOGGER_H_
#define FILE_ROLLER_LOGGER_H_

#include <string>

#include <moth/log/logger.h>

namespace moth {

class FileRollerLogger : public Logger {
public:
    FileRollerLogger(std::string classname);
    virtual ~FileRollerLogger();
    virtual void Write(std::string message);
};

} /* namespace moth */
#endif /* FILE_ROLLER_LOGGER_H_ */
