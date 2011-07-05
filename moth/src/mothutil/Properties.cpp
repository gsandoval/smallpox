/*
 * File.cpp
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <mothutil/Properties.h>
#include <mothutil/Tokenizer.h>

#include <iostream>
#include <fstream>
#include <sstream>

namespace moth {

Properties::Properties(string _filename) : filename(_filename) {
	loadProperties();
}

void Properties::loadProperties() {
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
			if (tok.tokenCount() != 2)
				continue;
			string key = trim(tok.nextToken());
			string value = trim(tok.nextToken());
			properties[key] = value;
		}
		file.close();
	}
}

Properties::~Properties() {
}

string Properties::get(string key, string def) {
	if (properties.find(key) != properties.end())
		return properties[key];
	return def;
}

int Properties::getInt(string key, int def) {
	int ret = def;
	if (properties.find(key) != properties.end())
		istringstream(properties.find(key)->second) >> ret;
	return ret;
}

double Properties::getDouble(string key, double def) {
	double ret = def;
	if (properties.find(key) != properties.end())
		istringstream(properties.find(key)->second) >> ret;
	return ret;
}

long long Properties::getLong(string key, long long def) {
	long long ret = def;
	if (properties.find(key) != properties.end())
		istringstream(properties.find(key)->second) >> ret;
	return ret;
}

char Properties::getChar(string key, char def) {
	char ret = def;
	if (properties.find(key) != properties.end())
		istringstream(properties.find(key)->second) >> ret;
	return ret;
}

bool Properties::getBool(string key, bool def) {
	bool ret = def;
	if (properties.find(key) != properties.end())
		istringstream(properties.find(key)->second) >> boolalpha >> ret;
	return ret;
}

} /* namespace moth */
