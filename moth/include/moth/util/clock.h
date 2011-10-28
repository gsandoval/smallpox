/*
 * clock.h
 *
 *  Created on: 11/09/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef CLOCK_H
#define CLOCK_H

#include <string>

namespace moth {

class Clock {
public:
    static long long CurrentTime();
    static std::string CurrentTimeString();
};

}/* namespace moth */
#endif // CLOCK_H
