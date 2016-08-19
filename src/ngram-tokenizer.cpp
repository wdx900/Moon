#include "ngram-tokenizer.h"

bool NGramTokenizer::DoTokenizerInteral(string &text, TokenBuffer &out_token) {
	UTF8Character character;
	int position = 0, length = 0, cur_position, cur_length, word_num = 0;
	character.SetCharacterText(text);
	int text_len = text.size();
	while(character.UTF8CharacterLexer(cur_position, cur_length)) {
		if(word_num < this->n_gram) {
			length += cur_length;
		} else {
			length = cur_length;
			word_num = 0;
			position = cur_position;
		}	
		++word_num;
		string word = text.substr(position, length);
		cout << word << endl;
		out_token.WriteToken(word);
	}
	return true;
}
