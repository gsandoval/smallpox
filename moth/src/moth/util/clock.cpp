/*
 * clock.cpp
 *
 *  Created on: 11/09/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <sstream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <sys/time.h>
#include <ctime>
#endif

#include <moth/util/clock.h>

namespace moth {

using namespace std;

long long Clock::CurrentTime() {
    long long m;
#ifdef _WIN32
    m = GetTickCount64();
#else
    timeval tv;
    gettimeofday(&tv, NULL);
    m = tv.tv_sec * 1000 + tv.tv_usec / 1000;
#endif
    return m;
}

std::string Clock::CurrentTimeString() {
    ostringstream oss;
    oss << setfill('0');
#ifdef _WIN32
    SYSTEMTIME systime;
    GetSystemTime(&systime);

    oss << systime.wYear << "-" << setw(2) << systime.wMonth << "-" << setw(2) << systime.wDay;
    oss << " " << setw(2) << systime.wHour << ":" << setw(2) << systime.wMinute << ":" << setw(2) << systime.wSecond;
    oss << "," << setw(3) << systime.wMilliseconds;
#else
    time_t t = time(NULL);
    tm* timeinfo = localtime(&t);
    timeval tv;
    gettimeofday(&tv, NULL);

    oss << timeinfo->tm_year + 1900 << "-" << setw(2) << timeinfo->tm_mon + 1 << "-" << setw(2) << timeinfo->tm_mday;
    oss << " " << setw(2) << timeinfo->tm_hour << ":" << setw(2) << timeinfo->tm_min << ":" << setw(2) << timeinfo->tm_sec;
    oss << "," << setw(3) << ((tv.tv_usec / 1000) % 1000);
#endif
    return oss.str();
}

}
