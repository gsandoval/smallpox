/*
 * File.h
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef FILE_H_
#define FILE_H_

#include <string>

using namespace std;

namespace moth {

class File {
public:
	File(string filename);
	virtual ~File();
	void open();
	void close();
	string readLine();
	bool hasMoreLines();
	char readChar();
	bool hasMoreChars();
private:
	string filename;
	fstream* file;
};

} /* namespace moth */
#endif /* FILE_H_ */
