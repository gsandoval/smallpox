/*
 * filerollerlogger.h
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef FILE_ROLLER_LOGGER_H_
#define FILE_ROLLER_LOGGER_H_

#include <moth/log/logger.h>

namespace moth {

class FileRollerLogger : public Logger {
public:
    FileRollerLogger(std::string classname);
    virtual ~FileRollerLogger();
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
#endif /* FILE_ROLLER_LOGGER_H_ */
