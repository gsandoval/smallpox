/*
 * Logger.h
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef FILE_ROLLER_LOGGER_H_
#define FILE_ROLLER_LOGGER_H_

#include <mothlog/Logger.h>

namespace moth {

class FileRollerLogger : public Logger {
public:
	FileRollerLogger(string className);
	virtual ~FileRollerLogger();
	virtual void info(string msg);
	virtual void info(string msg, MothException& e);
	virtual void debug(string msg);
	virtual void debug(string msg, MothException& e);
	virtual void warn(string msg);
	virtual void warn(string msg, MothException& e);
	virtual void error(string msg);
	virtual void error(string msg, MothException& e);
};

} /* namespace moth */
#endif /* FILE_ROLLER_LOGGER_H_ */
