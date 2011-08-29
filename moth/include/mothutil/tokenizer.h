/*
 * Tokenizer.h
 *
 *  Created on: 03/07/2011
 *      Author: darchitect
 */

#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include <string>
#include <vector>
#include <iterator>
#include <cstddef>

using namespace std;

namespace moth {

class Tokenizer {
public:
    struct iterator : std::iterator<input_iterator_tag, string> {
    private:
        vector<string>::iterator it;
    public:
        iterator(vector<string>::iterator it);
        iterator(const iterator& tit);
        iterator& operator++();
        iterator operator++(int);
        bool operator==(const iterator& rhs);
        bool operator!=(const iterator& rhs);
        string& operator*();
    };

    Tokenizer(string str, string delim = " ");
    virtual ~Tokenizer();
    iterator begin();
    iterator end();
private:
    vector<string> tokens;
    size_t curr_token;
};

} /* namespace moth */
#endif /* TOKENIZER_H_ */
