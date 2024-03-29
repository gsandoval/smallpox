/*
 * file.h
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef PROPERTIES_H_
#define PROPERTIES_H_

#include <string>
#include <map>

namespace moth {

class Properties {
public:
    Properties();
    Properties(std::string filename);
    virtual ~Properties();
    std::string Get(std::string key, std::string def = "");
    int GetInt(std::string key, int def = 0);
    double GetDouble(std::string key, double def = 0.0);
    long long GetLong(std::string key, long long def = 0);
    bool GetBool(std::string key, bool def = false);

private:
    std::map<std::string, std::string> properties;
    std::string filename;

    void LoadProperties();
};

} /* namespace moth */
#endif /* PROPERTIES_H_ */
