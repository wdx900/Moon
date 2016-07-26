#ifndef CHARATER_H
#define CHARATER_H

#include <iostream>
using namespace std;

class Charater {

public:
	Charater(){};
	virtual ~Charater(){}

public:
	bool UTF8CharaterLexer(int &position, int &length);
	bool SetCharaterText(const string &text);
private:
	string c_text;	
	int c_position;

};


#endif 
