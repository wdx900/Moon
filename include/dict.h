#ifndef DICT_H	
#define DICT_H

#include <iostream>
using namespace std;

class Dict {
public:
	virtual ~Dict() {}
	
public:
	virtual bool SaveTo(const string &file_name) = 0;
	virtual bool LoadFrom(const string &file_name) = 0;
	virtual bool Match() = 0;
};


#endif
