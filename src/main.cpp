#include <iostream>
#include "utf8-character.h"
#include "gbk-character.h"
#include "buffer-pool.h"
#include "token-buffer.h"
#include "token.h"
using namespace std;

int main() {
	const string words = "c中国人民";
	//const string words = "hello22";
	BufferPool buffer_pool;
	UTF8Character charater;
	TokenBuffer token_buffer;
	charater.SetCharacterText(words);
	int position,length;
	cout << "word size is " << words.size() << endl;
	while(charater.UTF8CharacterLexer(position, length)) {
	    string word = words.substr(position, length);
		buffer_pool.WriteString(word);
	}
	string t;
	
	TokenBuffer::Iterator iterator;
	
	//iterator.next(t);
//	cout << t.t_text << endl;
	
	//char* word_t = new char[1024];
	while(buffer_pool.ReadString(t)) {
		cout << t << endl;
	}
	//cout << byte << endl;
	//cout << words << endl;
	return 1;
}
