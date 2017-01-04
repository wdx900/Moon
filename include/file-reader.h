#ifndef FILE_READER_H
#define FILE_READER_H

#include <iostream>
#include <fstream>

using namespace std;

class FileReader{
public:
	bool open(const char* file);
	bool readline(char* str);

public:
	bool close();

private:
	fstream sfile;
};

#endif 
