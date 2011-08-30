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

namespace moth {

class Tokenizer {
public:
    struct iterator : std::iterator<std::input_iterator_tag, std::string> {
    private:
        std::vector<std::string>::iterator it;
    public:
        iterator(std::vector<std::string>::iterator it);
        iterator(const iterator& tit);
        iterator& operator++();
        iterator operator++(int);
        bool operator==(const iterator& rhs);
        bool operator!=(const iterator& rhs);
        std::string& operator*();
    };

    Tokenizer(std::string str, std::string delim = " ");
    virtual ~Tokenizer();
    iterator begin();
    iterator end();
private:
    std::vector<std::string> tokens;
    size_t curr_token;
};

} /* namespace moth */
#endif /* TOKENIZER_H_ */
