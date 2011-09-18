/*
 * loggerfactory.h
 *
 *  Created on: 31/08/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef LOGGERFACTORY_H_
#define LOGGERFACTORY_H_

#include <string>
#include <memory>

#include <moth/log/logger.h>

namespace moth {

class LoggerFactory {
public:
    LoggerFactory();
    virtual ~LoggerFactory();
    static std::shared_ptr<Logger> CreateLogger(std::string classname);
};

} /* namespace moth */
#endif /* LOGGERFACTORY_H_ */
