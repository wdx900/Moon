#include <iostream>
#include "utf8-character.h"
#include "gbk-character.h"
#include "buffer-pool.h"
using namespace std;

int main() {
	const string words = "c中国人民";
	BufferPool buffer_pool;
	UTF8Character charater;
	charater.SetCharacterText(words);
	int position,length;
	cout << "word size is " << words.size() << endl;
	while(charater.UTF8CharacterLexer(position, length)) {
		cout << position << " " << length << endl;
	    string word = words.substr(position, length);
		cout << word << endl;
		buffer_pool.WriteString(word);
	}
	//buffer_pool.WriteString("c");
	char* byte;
	int l = 0;
	//buffer_pool.GetPool(byte);
	while(buffer_pool.ReadString(byte, l)) {
		cout << byte << " " << l << endl;
	}
	//char* word_t = new char[1024];
	//buffer_pool.ReadString(word_t, l);
	//cout << word_t << endl;
	cout << byte << endl;
	cout << words << endl;
	return 1;
}
