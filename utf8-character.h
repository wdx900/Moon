#ifndef CHARATER_H
#define CHARATER_H

#include <iostream>
#include "base-character.h"

using namespace std;

class UTF8Character : public BaseCharacter {

public:
	UTF8Character(){};
	virtual ~UTF8Character(){}

public:
	bool UTF8CharacterLexer(int &position, int &length);
	//virtual bool SetCharacterText(const string &text);
private:
	//string c_text;	
	//int c_position;

};


#endif 
