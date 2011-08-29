/*
 * Tokenizer.cpp
 *
 *  Created on: 03/07/2011
 *      Author: darchitect
 */

#include <mothutil/tokenizer.h>

namespace moth {

using namespace std;

Tokenizer::Tokenizer(string line, string delim) {
    size_t start = 0, end = 0;
    while (end != string::npos) {
        end = string::npos;
        for (size_t i = 0; i < delim.size(); ++i) {
            size_t currPos = line.find(delim.substr(i, 1), start);
            if (currPos != string::npos) {
                if (end == string::npos)
                    end = currPos;
                else if (end > currPos)
                    end = currPos;
            }
        }

        tokens.push_back(line.substr(start, (end == string::npos) ? line.size() - start : end - start ));

        start = end + 1;
    }
}

Tokenizer::iterator Tokenizer::begin()
{
    return Tokenizer::iterator(tokens.begin());
}

Tokenizer::iterator Tokenizer::end()
{
    return Tokenizer::iterator(tokens.end());
}

Tokenizer::~Tokenizer() {
}

Tokenizer::iterator::iterator(vector<string>::iterator _it) : it(_it)
{
}

Tokenizer::iterator::iterator(const Tokenizer::iterator& _it) : it(_it.it)
{
}

Tokenizer::iterator& Tokenizer::iterator::operator++()
{
    ++it;
    return *this;
}

Tokenizer::iterator Tokenizer::iterator::operator++(int)
{
    Tokenizer::iterator tmp(*this);
    operator++();
    return tmp;
}

bool Tokenizer::iterator::operator==(const Tokenizer::iterator& rhs)
{
    return it == rhs.it;
}

bool Tokenizer::iterator::operator!=(const Tokenizer::iterator& rhs)
{
    return it != rhs.it;
}

string& Tokenizer::iterator::operator*()
{
    return *it;
}

} /* namespace moth */
