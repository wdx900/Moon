#include <iostream>
#include "utf8-character.h"
#include "gbk-character.h"
#include "buffer-pool.h"
#include "token-buffer.h"
#include "token.h"
#include "trie-node.h"
#include "file-reader.h"
#include "ngram-tokenizer.h"

using namespace std;

int main() {
	Trie *trie = new Trie;
	FileReader file_reader;
	if(file_reader.open("dict")) {
		cout << "open file is OK" << endl;
	}
	
	char* str = new char[100];
	while(file_reader.readline(str)) {
		int position, length;
		vector<int> words_list;
	    UTF8Character character;
		TokenBuffer *token_buffer = new TokenBuffer;
		string words(str);
		character.SetCharacterText(words);	
		if(words.size() == 0) continue;
		while(character.UTF8CharacterLexer(position, length)) {
			//string word = words.substr(position, length);
			//if(word.size() == 1) break;
			//token_buffer->WriteString(word);	
			if(length == 1)break;
			words_list.push_back(length);
		}
		trie->insert(words, words_list);
			
	}
	file_reader.close();
	cout << "read file is fininshed" << endl;	

	/*string test_word = "你好";
	cout << test_word << endl;
	UTF8Character test_character;
	TokenBuffer *test_buffer = new TokenBuffer;
	test_character.SetCharacterText(test_word);
	int position, length;
	while(test_character.UTF8CharacterLexer(position, length)) {
        string word = test_word.substr(position, length);
        test_buffer->WriteString(word);
    }
	if(trie->find(test_buffer)) {
		cout << "find word !" << endl;
	} else {
		cout << "not find!!" << endl;
	}*/
	string test_str = "今天天气真好";
	string word_test = "";
	NGramTokenizer ngram_tokenizer;
	ngram_tokenizer.SetNGram(3);
	vector<string> words_str;
	ngram_tokenizer.DoTokenizerInteral(test_str, words_str);
	for(int i = 0; i < words_str.size(); ++i) {
		vector<int> length_list;
		UTF8Character character;
		character.SetCharacterText(words_str[i]);
		int position, length;
		while(character.UTF8CharacterLexer(position, length)) {
			length_list.push_back(length);
		}
		if(trie->find(words_str[i], length_list)) {
			cout << words_str[i] << endl;
		} 	
	}
	return 1;
}
