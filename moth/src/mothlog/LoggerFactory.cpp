/*
 * LoggerFactory.cpp
 *
 *  Created on: 04/07/2011
 *      Author: darchitect
 */

#include <mothlog/LoggerFactory.h>

namespace moth {

LoggerFactory::LoggerFactory() {

}

LoggerFactory::~LoggerFactory() {
}

Logger* LoggerFactory::createLogger(string className) {
	return NULL;
}

} /* namespace moth */
