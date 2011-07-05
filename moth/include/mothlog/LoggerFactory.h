/*
 * LoggerFactory.h
 *
 *  Created on: 04/07/2011
 *      Author: darchitect
 */

#ifndef LOGGERFACTORY_H_
#define LOGGERFACTORY_H_

#include <string>

using namespace std;

namespace moth {

class LoggerFactory {
public:
	LoggerFactory();
	virtual ~LoggerFactory();
	Logger* createLogger(string className);
};

} /* namespace moth */
#endif /* LOGGERFACTORY_H_ */
