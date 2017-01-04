#ifndef TOOL_H
#define TOOL_H

#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

namespace TOOL {
	
    inline int cmp(const pair<string, double>& x, const pair<string, double>& y) {
        return x.second > y.second;
    }	
	bool judge_alphabet(string alp);
	bool sortMapbyValue(map<string, double>& t_map, vector<pair<string, double> > &t_vec);

};

namespace STRING {
	bool split(string &s, string& delim, vector<string> &ret);
};

#endif
