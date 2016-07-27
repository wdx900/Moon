#include <iostream>
#include "utf8-character.h"
#include "gbk-character.h"
using namespace std;

int main() {
	const string word = "c中国人民";
	UTF8Character charater;
	charater.SetCharacterText(word);
	int position,length;
	cout << "word size is " << word.size() << endl;
	while(charater.UTF8CharacterLexer(position, length)){
		cout << position << " " << length << endl;
		cout << word.substr(position, length) << endl;
	}
	cout << word << endl;
	return 1;
}
