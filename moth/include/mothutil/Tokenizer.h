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

using namespace std;

namespace moth {

class Tokenizer {
public:
	Tokenizer(string str, string delim = " ");
	virtual ~Tokenizer();
	bool hasMoreTokens();
	size_t tokenCount();
	string nextToken();
private:
	vector<string> tokens;
	size_t currToken;
};

} /* namespace moth */
#endif /* TOKENIZER_H_ */
