/*
 * Config.cpp
 *
 *  Created on: 02/07/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <mothutil/Properties.h>

#include <iostream>

int main(int argc, char* argv[]) {
	moth::Properties p("test.properties");
	cout << "str: " << p.get("testStr") << endl;
	cout << "str: " << p.get("testStr1") << endl;
	cout << "double: " << p.getDouble("testDouble") << endl;
	cout << "bool: " << boolalpha << p.getBool("testBool") << endl;
	cout << "bool: " << boolalpha << p.getBool("testBool1") << endl;
	cout << "int: " << p.getInt("testBool1") << endl;
	return 0;
}

