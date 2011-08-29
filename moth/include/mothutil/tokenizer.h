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
	bool HasMoreTokens();
	size_t TokenCount();
	string NextToken();
private:
	vector<string> tokens;
	size_t curr_token;
};

} /* namespace moth */
#endif /* TOKENIZER_H_ */
