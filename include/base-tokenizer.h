#ifndef BASE_TOKENIZER_H
#define BASE_TOKENIZER_H

#include <iostream>
#include <vector>
#include "utf8-character.h"
#include "token-buffer.h"
//#include "trie-node.h"
#include "base-tokenizer.h"

using namespace std;

class BaseTokenizer {

public:
	BaseTokenizer() {};
	virtual ~BaseTokenizer() {};
	
public:
	bool DoTokenizer(); 
protected:
	virtual bool DoTokenizerInteral(string &text, vector<string> &words_str) = 0;	
	bool WriteTokenBuffer(TokenBuffer *token_buffer, string str);

protected:
//	static Trie *trie;
};


#endif
