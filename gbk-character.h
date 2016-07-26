#ifndef GBK_CHARACTER_H
#define GBK_CHARACTER_H

#include <iostream>
#include "base-character.h"
using namespace std;

class GBKCharacter : public BaseCharacter {

public:
	GBKCharacter(){};
	virtual ~GBKCharacter(){};

public:
	bool GBKCharacterLexer(int &position, int &length); 
		
};


#endif
