#ifndef FORWARD_TOKENIZER_H
#define FORWARD_TOKENIZER_H
#include <iostream>

#include "utf8-character.h"
#include "base-tokenizer.h"
#include "file-reader.h"
#include "trie-node.h"
#include "tool.h"

using namespace std;

class ForwardTokenizer : public BaseTokenizer {
public:
	ForwardTokenizer(){};
	virtual ~ForwardTokenizer(){};

public:
	virtual bool DoTokenizerInteral(string &text, vector<string> &word_str);

};


#endif
