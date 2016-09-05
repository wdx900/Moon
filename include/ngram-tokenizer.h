#ifndef NGRAM_TOKENIZER_H
#define NGRAM_TOKENIZER_H

#include <iostream>
#include <vector>
#include "utf8-character.h"
#include "token-buffer.h"
#include "base-tokenizer.h"

using namespace std;

class NGramTokenizer : public BaseTokenizer {
public:
	NGramTokenizer(){};
	virtual ~NGramTokenizer(){};
	

public:
    virtual bool DoTokenizerInteral(string &text, vector<string> &words_str);
	bool SetNGram(int num);	
	bool WriteTokenBuffer(TokenBuffer *token_buffer, string str);
private:
	int n_gram;
};

inline bool NGramTokenizer::SetNGram(int num) {
	this->n_gram = num;
	return true;
}

#endif
