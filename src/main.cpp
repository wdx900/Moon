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
#include "keywords.h"

using namespace std;

int main() {
	ForwardTokenizer forward_tokenizer;
	string text = "阅读是从视觉材料中获取信息的过程。视觉材料主要是文字和图片，也包括符号、公式、图表等。首先是把视觉材料变成声音，后达到对视觉材料的理解。阅读是一种主动的过程，是由阅读者根据不同的目的加以调节控制的,陶冶人们的情操，提升自我修养。阅读是一种理解，领悟，吸收，鉴赏，评价和探究文章的思维过程。阅读分为出声读和默看。";
	vector<string> words;
	map<string, double> word_c;
	forward_tokenizer.DoTokenizerInteral(text, words);
	for(int i = 0; i < words.size(); ++i) {
		if(word_c.find(words[i]) != word_c.end()) {
			word_c[words[i]] += 1;
		} else {
			word_c.insert(pair<string, double>(words[i], 1));
		}
	}
	Keywords keywords;
	vector<string> word_list;
	keywords.getWordIDF("news.df.dat");
	keywords.getKeywords(word_c, word_list, 10);	
	for(int i = 0; i < word_list.size(); i++) {
		cout << word_list[i] << ",";
	}
	cout << endl;
	return 1;
}
