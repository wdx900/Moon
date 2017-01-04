#include "tool.h"

bool TOOL::judge_alphabet(string alp) {
	for(int i = 0; i < alp.size(); ++i) {
		if((unsigned int)alp[i] >= 128) {
			return false;
		}
	}
	return true;
}

bool TOOL::sortMapbyValue(map<string, double>& t_map, vector<pair<string, double> > &t_vec) {
    for(map<string,double>::iterator iter = t_map.begin();iter != t_map.end(); iter++) {
        t_vec.push_back(make_pair(iter->first,iter->second));
    }
    sort(t_vec.begin(),t_vec.end(),cmp);
    return true;
}

bool STRING::split(string &s, string& delim, vector<string> &ret) {
	size_t last = 0;
    size_t index = s.find_first_of(delim.c_str(), last);
    while (index != std::string::npos) {
        ret.push_back(s.substr(last, index - last));
        last = index + 1;
        index=s.find_first_of(delim, last);
    }
    if (index - last > 0) {
        ret.push_back(s.substr(last, index - last));
    }
    return true;
}
