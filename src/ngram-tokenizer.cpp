#include "ngram-tokenizer.h"

bool NGramTokenizer::DoTokenizerInteral(string &text, vector<string> &words_str) {
	vector<int> length_list;
	UTF8Character character;
	int position = 0, length = 0, cur_position, cur_length, word_num = 0;
	character.SetCharacterText(text);
	int text_len = text.size();
	while(character.UTF8CharacterLexer(cur_position, cur_length)) {
		length_list.push_back(cur_length);
	}	
	for(int i = 0; i < length_list.size(); ++i){
		for(int j = 0; j < this->n_gram; ++j){
			if((i + j) >= length_list.size()) {
				break;
			}
			length +=length_list[i + j];
			string word = text.substr(position, length);
			words_str.push_back(word);
		}
		position += length_list[i]; 
		length = 0;		

	}
	return true;
}

bool NGramTokenizer::WriteTokenBuffer(TokenBuffer *token_buffer, string str){
	UTF8Character character;
	int position, length;
	character.SetCharacterText(str);
	while(character.UTF8CharacterLexer(position, length)) {
		string word = str.substr(position, length);
		token_buffer->WriteString(word);
	}
	return true;
}
