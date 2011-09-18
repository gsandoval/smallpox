/*
 * clock.cpp
 *
 *  Created on: 11/09/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <sys/time.h>
#include <cstdlib>

#include <moth/util/clock.h>

namespace moth {

long long Clock::CurrentTime() {
    timeval tv;
    gettimeofday(&tv, NULL);
    long long m = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    return m;
}

}
