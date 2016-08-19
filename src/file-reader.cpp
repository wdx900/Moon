#include "file-reader.h"

bool FileReader::open(char* file) {
	this->sfile.open(file);	
	if(this->sfile.is_open()){
		return true;
	}	
	return false;
}

bool FileReader::readline(char* str) {
	if(!this->sfile.eof()) {
		this->sfile.getline(str, 100);
		return true;
	}
	return false;
}

bool FileReader::close() {
	if(this->sfile.is_open()) {
		this->sfile.close();
		return true;
	}
	return false;
}


