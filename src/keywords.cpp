#include "keywords.h"

Keywords::Keywords(string file, string text) {
	getWordIDF(file);
	getWordTf(text);
}

bool Keywords::getWordIDF(string file) {
	open(file.c_str());
	char * str = new char[100];
	while(readline(str)) {
		string word_tmp(str);
		string delim = " ";
		vector<string> dot;
		STRING::split(word_tmp, delim, dot);
		if(dot.size() < 3){
			continue;
		}
		this->idf_map.insert(pair<string, float>(dot[0], atof(dot[2].c_str())));
	}
	close();
	return true;
}

bool Keywords::getWordTf(string text) {
	vector<string> words;
	forward_tokenizer.DoTokenizerInteral(text, words);
	tf_map.clear();
	for(int i = 0; i < words.size(); ++i) {
		if(tf_map.find(words[i]) != tf_map.end()) {
			tf_map[words[i]] += 1;
		} else {
			tf_map.insert(pair<string, double>(words[i], 1));
		}
	}
	return true;
}

bool Keywords::getKeywords(vector<pair<string, double> > &keywords, int num) {
	map<string, double>::iterator iter = tf_map.begin();
	for(; iter != tf_map.end(); ++iter) {
		tf_map[iter->first]  *= idf_map[iter->first];
	}
	vector<pair<string, double> > t_vec;
	TOOL::sortMapbyValue(tf_map, t_vec);
	for(int i = 0; i < t_vec.size() && i < num; ++i) {
		if(t_vec[i].second > 0){
			keywords.push_back(t_vec[i]);
		} else {
			break;
		}
	}	
	return true;
}

