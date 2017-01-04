#include "keywords.h"

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

bool Keywords::getKeywords(map<string, double> word_c, vector<string> &keywords, int num) {
	map<string, double>::iterator iter = word_c.begin();
	for(; iter != word_c.end(); ++iter) {
		word_c[iter->first]  *= idf_map[iter->first];
	}
	vector<pair<string, double> > t_vec;
	TOOL::sortMapbyValue(word_c, t_vec);
	for(int i = 0; i < t_vec.size() && i < num; ++i) {
		cout << t_vec[i].first << ":" << t_vec[i].second << endl;
		if(t_vec[i].second > 0){
			keywords.push_back(t_vec[i].first);
		} else {
			break;
		}
	}	
	
	return true;
}

