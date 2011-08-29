#include <iostream>
#include <mothutil/tokenizer.h>

using namespace std;

int main(int argc, char* argv[])
{
    moth::Tokenizer tok("hello heartbit beautiful people!");
    for (auto it = tok.begin(); it != tok.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}
