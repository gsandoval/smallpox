/*
 * LoggerFactory.h
 *
 *  Created on: 04/07/2011
 *      Author: darchitect
 */

#ifndef LOGGERFACTORY_H_
#define LOGGERFACTORY_H_

#include <string>

#include <mothlog/logger.h>

using namespace std;

namespace moth {

class LoggerFactory {
public:
	LoggerFactory();
	virtual ~LoggerFactory();
	static Logger* CreateLogger(string classname);
};

} /* namespace moth */
#endif /* LOGGERFACTORY_H_ */
