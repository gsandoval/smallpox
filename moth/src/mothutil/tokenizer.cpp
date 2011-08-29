/*
 * Tokenizer.cpp
 *
 *  Created on: 03/07/2011
 *      Author: darchitect
 */

#include <mothutil/tokenizer.h>

namespace moth {

Tokenizer::Tokenizer(string line, string delim) : curr_token(0) {
	size_t start = 0, end = 0;
	while (end != string::npos) {
		end = string::npos;
		for (int i = 0; i < delim.size(); ++i) {
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

Tokenizer::~Tokenizer() {
}

bool Tokenizer::HasMoreTokens() {
	return (tokens.size() - curr_token) > 0;
}

size_t Tokenizer::TokenCount() {
	return tokens.size();
}

string Tokenizer::NextToken() {
	return tokens[curr_token++];
}

} /* namespace moth */
