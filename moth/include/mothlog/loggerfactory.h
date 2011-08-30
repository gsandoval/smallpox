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

namespace moth {

class LoggerFactory {
public:
    LoggerFactory();
    virtual ~LoggerFactory();
    static Logger* CreateLogger(std::string classname);
};

} /* namespace moth */
#endif /* LOGGERFACTORY_H_ */
