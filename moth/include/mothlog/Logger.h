/*
 * Logger.h
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>

using namespace std;

namespace moth {

class MothException;

class Logger {
public:
	Logger(string classname);
	virtual ~Logger();
	virtual void Info(string msg) = 0;
	virtual void Info(string msg, MothException* e) = 0;
	virtual void Debug(string msg) = 0;
	virtual void Debug(string msg, MothException* e) = 0;
	virtual void Warn(string msg) = 0;
	virtual void Warn(string msg, MothException* e) = 0;
	virtual void Error(string msg) = 0;
	virtual void Error(string msg, MothException* e) = 0;
protected:
	string classname;

	virtual string DateTime();
};

} /* namespace moth */
#endif /* LOGGER_H_ */
