/*
 * Logger.h
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <mothutil/MothException>

#include <string>

using namespace std;

namespace moth {

class Logger {
public:
	Logger(string className);
	virtual ~Logger();
	virtual void info(string msg) = 0;
	virtual void info(string msg, MothException& e) = 0;
	virtual void debug(string msg) = 0;
	virtual void debug(string msg, MothException& e) = 0;
	virtual void warn(string msg) = 0;
	virtual void warn(string msg, MothException& e) = 0;
	virtual void error(string msg) = 0;
	virtual void error(string msg, MothException& e) = 0;
protected:
	string className;
};

} /* namespace moth */
#endif /* LOGGER_H_ */
