#ifndef NGRAM_TOKENIZER_H
#define NGRAM_TOKENIZER_H

#include <iostream>
#include "utf8-character.h"
#include "token-buffer.h"
#include "base-tokenizer.h"

using namespace std;

class NGramTokenizer : public BaseTokenizer {
public:
	//NGramTokenizer(){};
	//virtual ~NGramTokenizer(){};
	

public:
	bool DoTokenizerInteral(string &text, TokenBuffer &out_token);
	bool SetNGram(int num);	
private:
	int n_gram;
};

inline bool NGramTokenizer::SetNGram(int num) {
	this->n_gram = num;
	return true;
}

#endif
