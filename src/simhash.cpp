#include "simhash.h"

SimHash::SimHash(string path) {
	k_handler.getWordIDF(path);	
}

bool SimHash::calculateHash(string& text, long& v64) {
	vector<pair<string, double> > word_list;
	vector<pair<long, double> > hash_values;
	k_handler.getWordTf(text);
	k_handler.getKeywords(word_list, 6);
	hash_values.resize(word_list.size());
	for(int i = 0; i < hash_values.size(); ++i) {
        hash_values[i].first = _hasher(word_list[i].first.c_str(), word_list[i].first.size(), 0);
        hash_values[i].second = word_list[i].second;
    }
	vector<double> weights(BITS_LENGTH, 0.0);
	const long u64_1(1);
	for(int i = 0; i < hash_values.size(); ++i) {
		for(int j = 0; j < BITS_LENGTH; ++j) {
			weights[j] += (((u64_1 << j) & hash_values[i].first) ? 1: -1) * hash_values[i].second;
		}
	}
	v64 = 0;
	for(int i = 0; i < BITS_LENGTH; ++i) {
		if(weights[i] > 0.0) {
			v64 |= (u64_1 << i);
		}
	}
	return true;

}

bool SimHash::isEqual(long lhs, long rhs, int n) {
	int count = 0;
    lhs ^= rhs;
    while(lhs && count <= n) {
        lhs &= lhs - 1;
        ++count;
    }
    if(count <= n) {
        return true;
    }
    return false;
}
