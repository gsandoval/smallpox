/*
 * Logger.h
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef FILE_LOGGER_H_
#define FILE_LOGGER_H_

#include <mothlog/Logger.h>

namespace moth {

class FileLogger : public Logger {
public:
	FileLogger(string className);
	virtual ~FileLogger();
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
#endif /* FILE_LOGGER_H_ */
