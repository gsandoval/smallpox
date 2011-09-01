/*
 * util.cpp
 *
 *  Created on: 02/07/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <mothutil/properties.h>

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    moth::Properties p("test.properties");
    cout << "str: " << p.Get("testStr") << endl;
    cout << "str: " << p.Get("testStr1") << endl;
    cout << "double: " << p.GetDouble("testDouble") << endl;
    cout << "bool: " << boolalpha << p.GetBool("testBool") << endl;
    cout << "bool: " << boolalpha << p.GetBool("testBool1") << endl;
    cout << "int: " << p.GetInt("testBool1") << endl;
    return 0;
}

