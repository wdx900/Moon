#ifndef KEYWORDS_H
#define KEYWORDS_H

#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>

#include "tool.h"
#include "file-reader.h"

using namespace std;

class Keywords : public FileReader {
public:
	Keywords(){};
	virtual ~Keywords(){};

public:
	bool getWordIDF(string file);
	bool getKeywords(map<string, double> word_c, vector<string> &keywords, int num);
private:
	map<string, float> idf_map;
	

};

#endif
