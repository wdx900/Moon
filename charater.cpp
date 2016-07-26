#include "charater.h"

bool Charater::SetCharaterText(const string &text) {
	this->c_text = text;
	this->c_position = 0;
	return true;
}

bool Charater::UTF8CharaterLexer(int &position, int &length) {
	if(this->c_text.size() == 0) {
		return false;
	}
	length = 0;
	position = this->c_position;
	int cur_position = this->c_position;
	if(position >= c_text.size()) {
		return false;
	}	
	if((this->c_text[position] & 0x80) == 0x00) {
		length = 1;
	} else if((this->c_text[position] & 0x40) == 0x40) {
		if((this->c_text[position] & 0x20) == 0x00) { 
			length = 2;
		} else if((this->c_text[position] & 0x10) == 0x00) {
			length = 3;
		} else {
			return false;
		}
	}
	if((position + length) > c_text.size()){
		return false;
	}
	this->c_position = position + length;
	return true;
		
}
