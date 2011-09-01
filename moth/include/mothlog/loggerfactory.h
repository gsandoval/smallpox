/*
 * loggerfactory.h
 *
 *  Created on: 31/08/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
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
