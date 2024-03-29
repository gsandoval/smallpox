/*
 * tok.cpp
 *
 *  Created on: 31/08/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <iostream>
#include <algorithm>
#include <string>

#include <moth/util/tokenizer.h>

using namespace std;

int main(int argc, char* argv[])
{
    moth::Tokenizer tok("hello heartbit beautiful people!");
    cout << distance(tok.begin(), tok.end()) << endl;
    for_each(tok.begin(), tok.end(), [](string &t) { cout << t << endl;});
    return 0;
}
