/*
 * Log.cpp
 *
 *  Created on: 05/07/2011
 *      Author: darchitect
 */

#include <mothlog/loggerfactory.h>

int main(int argc, char* argv[]) {
	moth::Logger* logger = moth::LoggerFactory::CreateLogger(__FILE__);
	logger->Error("Hello world");
	return 0;
}

