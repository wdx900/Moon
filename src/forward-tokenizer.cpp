#include "forward-tokenizer.h"

bool ForwardTokenizer::DoTokenizerInteral(string &text, vector<string> &words_str) {
	FileReader file_reader;
	Trie *trie = new Trie;
	if(file_reader.open("dict")) {
		cout << "Open file is OK" << endl;
	}
	UTF8Character character;
	char* str = new char[100];
	while(file_reader.readline(str)) {
		int position, length;
		vector<int> words_list;
		TokenBuffer *token_buffer = new TokenBuffer;
		string words(str);
		character.SetCharacterText(words);
		if(words.size() == 0) continue;
		while(character.UTF8CharacterLexer(position, length)) {
			if(length == 1)break;
			words_list.push_back(length);
		}
		trie->insert(words, words_list);
	}
	
	file_reader.close();

	
	vector<int> length_list, position_list;
	character.SetCharacterText(text);
	int text_len = text.size();
	int cur_position, cur_length;
	while(character.UTF8CharacterLexer(cur_position, cur_length)) {
		length_list.push_back(cur_length);
		position_list.push_back(cur_position);
	}
	cur_position = 0;
	int start_index = 0;
	int error_t = 0;
	while(cur_position < text.size() - 1) {
		start:
		int end_position = text.size() - cur_position;
		for(int i = start_index; i < length_list.size(); ++i) {
			int tmp_position = end_position;
			for(int j = length_list.size(); j > 0; --j) {
				string word = text.substr(cur_position, tmp_position);
				if(word.size() == 0) {
					break;
				}
				vector<int> tmp_list(length_list.begin() + start_index, length_list.begin() + j);
				if(TOOL::judge_alphabet(word)) {
					words_str.push_back(word);
					cur_position = position_list[j];
                    start_index += tmp_list.size();
                    goto start;
				}else if(trie->find(word, tmp_list)){
					words_str.push_back(word);
					cur_position = position_list[j];
					start_index += tmp_list.size();
					goto start;
				}
					
				tmp_position -= length_list[j - 1];
			}
			end_position -= length_list[length_list.size() - i - 1];
		}	
		++error_t;
		if(error_t > 1000) {
			break;
		} 
	}
}
