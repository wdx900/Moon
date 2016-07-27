#ifndef BASE_CHARATER_H
#define BASE_CHARATER_H

#include <iostream>
using namespace std;

class BaseCharacter {

public:
	BaseCharacter(){};
	virtual ~BaseCharacter(){};

public:
	virtual bool SetCharacterText(const string &text);

protected:
	string c_text;
	int c_position;	
};

#endif
