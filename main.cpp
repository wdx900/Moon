#include <iostream>
#include "charater.h"

using namespace std;

int main() {
	const string word = "c中国人民";
	Charater charater;
	charater.SetCharaterText(word);
	int position,length;
	cout << "word size is " << word.size() << endl;
	while(charater.UTF8CharaterLexer(position, length)){
		cout << position << " " << length << endl;
	}
	cout << word << endl;
	return 1;
}
