/*
 * File.h
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef FILE_H_
#define FILE_H_

#include <string>
#include <map>

using namespace std;

namespace moth {

class Properties {
public:
    Properties(string filename);
    virtual ~Properties();
    string Get(string key, string def = "");
    int GetInt(string key, int def = 0);
    double GetDouble(string key, double def = 0.0);
    long long GetLong(string key, long long def = 0);
    char GetChar(string key, char def = 0);
    bool GetBool(string key, bool def = false);

private:
    map<string, string> properties;
    string filename;

    void LoadProperties();
};

} /* namespace moth */
#endif /* FILE_H_ */
