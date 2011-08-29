#include <iostream>
#include <algorithm>
#include <string>

#include <mothutil/tokenizer.h>

using namespace std;

int main(int argc, char* argv[])
{
    moth::Tokenizer tok("hello heartbit beautiful people!");
    cout << distance(tok.begin(), tok.end()) << endl;
    for_each(tok.begin(), tok.end(), [](string &t) { cout << t << endl;});
    return 0;
}
