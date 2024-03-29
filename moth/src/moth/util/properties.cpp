/*
 * properties.cpp
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <iostream>
#include <fstream>
#include <sstream>

#include <moth/util/properties.h>
#include <moth/util/tokenizer.h>

namespace moth {

using namespace std;

Properties::Properties() {

}

Properties::Properties(string _filename) : filename(_filename) {
    LoadProperties();
}

void Properties::LoadProperties() {
    fstream file(filename.c_str());
    if (file.is_open()) {
        string line;
        auto trim = [](string str) {
            int pos = str.find_first_not_of(' ');
            string copy = str.substr(pos, str.size() - pos);
            pos = copy.find(' ');
            copy = copy.substr(0, copy.size() - (copy.size() - pos));
            return copy;
        };
        while (file.good() && getline(file, line) > 0) {
            Tokenizer tok(line, "=");
            if (distance(tok.begin(), tok.end()) != 2)
                continue;
            auto it = tok.begin();
            string key = trim(*it++);
            string value = trim(*it);
            properties[key] = value;
        }
        file.close();
    }
}

Properties::~Properties() {
}

string Properties::Get(string key, string def) {
    if (properties.find(key) != properties.end())
        return properties[key];
    return def;
}

int Properties::GetInt(string key, int def) {
    int ret = def;
    if (properties.find(key) != properties.end())
        istringstream(properties.find(key)->second) >> ret;
    return ret;
}

double Properties::GetDouble(string key, double def) {
    double ret = def;
    if (properties.find(key) != properties.end())
        istringstream(properties.find(key)->second) >> ret;
    return ret;
}

long long Properties::GetLong(string key, long long def) {
    long long ret = def;
    if (properties.find(key) != properties.end())
        istringstream(properties.find(key)->second) >> ret;
    return ret;
}

bool Properties::GetBool(string key, bool def) {
    bool ret = def;
    if (properties.find(key) != properties.end())
        istringstream(properties.find(key)->second) >> boolalpha >> ret;
    return ret;
}

} /* namespace moth */
