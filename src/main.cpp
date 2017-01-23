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
#include "simhash.h"

using namespace std;

int main() {
	ForwardTokenizer forward_tokenizer;
	string text = "山东二孩出生量超一孩";
	string text1 = "山东二孩出生量超一孩";
	
	//Keywords keywords("news.df.dat", text);
	//vector<pair<string, double> > word_list;
	//keywords.getWordTf(text);
	//keywords.getWordIDF("news.df.dat");
	/*keywords.getKeywords(word_list, 10);	
	for(int i = 0; i < word_list.size(); i++) {
		cout << word_list[i].first << ",";
	}*/
	SimHash simhash("news.df.dat");
	long v64 = 0, v64_1 = 0;
	simhash.calculateHash(text, v64);
	simhash.calculateHash(text1, v64_1);
	cout << v64 << endl;
	cout << v64_1 << endl;
	if(simhash.isEqual(v64, v64_1)) {
		cout << "same" << endl;
	} else {
		cout << "different" << endl;
	}
	cout << endl;
	return 1;
}
