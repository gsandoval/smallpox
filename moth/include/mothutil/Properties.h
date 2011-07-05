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
	string get(string key, string def = "");
	int getInt(string key, int def = 0);
	double getDouble(string key, double def = 0.0);
	long long getLong(string key, long long def = 0);
	char getChar(string key, char def = 0);
	bool getBool(string key, bool def = false);

private:
	map<string, string> properties;
	string filename;

	void loadProperties();
};

} /* namespace moth */
#endif /* FILE_H_ */
