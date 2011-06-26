#include <iostream>
#include "utf8-character.h"
#include "gbk-character.h"
#include "buffer-pool.h"
#include "token-buffer.h"
#include "token.h"
#include "trie-node.h"
using namespace std;

int main() {
	const string words = "c中国人民";
	//const string words = "hello22";
	BufferPool buffer_pool;
	UTF8Character charater, test_charater;
	TokenBuffer token_buffer,test_buffer;
	charater.SetCharacterText(words);
	test_charater.SetCharacterText(words);
	int position,length;
	cout << "word size is " << words.size() << endl;
	while(charater.UTF8CharacterLexer(position, length)) {
	    string word = words.substr(position, length);
		token_buffer.WriteString(word);
	}
	string t;
	//Token token;
	Trie trie;
	trie.insert(token_buffer);

	while(test_charater.UTF8CharacterLexer(position, length)) {
        string word = words.substr(position, length);
        test_buffer.WriteString(word);
    }
	if(trie.find(test_buffer)) {
		cout << "find word !" << endl;
	}
	//TokenBuffer::Iterator *token_iterator = token_buffer.iterator();
	
	
	
	//while(token_iterator->next(token)) {
	//	cout << token.t_text << endl;
	//}
	
	//char* word_t = new char[1024];
//	while(buffer_pool.ReadString(t)) {
//		cout << t << endl;
//	}
	//cout << byte << endl;
	//cout << words << endl;
	return 1;
}
