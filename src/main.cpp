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
	    UTF8Character character;
		TokenBuffer *token_buffer = new TokenBuffer;
		string words(str);
		character.SetCharacterText(words);	
		if(words.size() == 0) continue;
		while(character.UTF8CharacterLexer(position, length)) {
			string word = words.substr(position, length);
			if(word.size() == 1) break;
			token_buffer->WriteString(word);	
		}
		trie->insert(token_buffer);
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
	string test_str = "北京欢迎你";
	NGramTokenizer ngram_tokenizer;
	ngram_tokenizer.SetNGram(3);
	TokenBuffer out_tokens;
	ngram_tokenizer.DoTokenizerInteral(test_str, out_tokens);
		

	return 1;
}
