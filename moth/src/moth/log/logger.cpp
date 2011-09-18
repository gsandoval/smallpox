/*
 * logger.cpp
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <sys/time.h>

#include <iomanip>
#include <ctime>
#include <sstream>

#include <moth/log/logger.h>

namespace moth {

using namespace std;

Logger::Logger(string _classname) : classname(_classname) {

}

Logger::~Logger() {
}

string Logger::DateTime() {
    time_t t = time(NULL);
    tm* timeinfo = localtime(&t);
    timeval tv;
    gettimeofday(&tv, NULL);

    ostringstream oss;
    oss << setfill('0');
    oss << timeinfo->tm_year + 1900 << "-" << setw(2) << timeinfo->tm_mon + 1 << "-" << setw(2) << timeinfo->tm_mday;
    oss << " " << setw(2) << timeinfo->tm_hour << ":" << setw(2) << timeinfo->tm_min << ":" << setw(2) << timeinfo->tm_sec;
    oss << "," << ((tv.tv_usec / 1000) % 1000);
    return oss.str();
}

} /* namespace moth */
