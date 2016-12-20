#include <iostream>
#include "utf8-character.h"
#include "gbk-character.h"
#include "buffer-pool.h"
#include "token-buffer.h"
#include "token.h"
//#include "trie-node.h"
#include "file-reader.h"
#include "ngram-tokenizer.h"
#include "forward-tokenizer.h"

using namespace std;

int main() {
	ForwardTokenizer forward_tokenizer;
	string text = "你好，今天是星期天。";
	vector<string> words;
	forward_tokenizer.DoTokenizerInteral(text, words);
	return 1;
}
