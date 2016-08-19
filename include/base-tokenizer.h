#ifndef BASE_TOKENIZER_H
#define BASE_TOKENIZER_H

#include <iostream>
#include "token-buffer.h"

using namespace std;

class BaseTokenizer {

public:
	//BaseTokenizer() {};
	//virtual ~BaseTokenizer() {};
	
public:
	bool DoTokenizer();

protected:
	//virtual bool DoTokenizerInteral(string &text, TokenBuffer &out_token);	

};


#endif
