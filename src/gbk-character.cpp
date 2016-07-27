#include "gbk-character.h"

bool GBKCharacter::GBKCharacterLexer(int &position, int &length) {
	if(this->c_text.size() == 0) {
		return false;
	}
	position = this->c_position;
	length = 0;
	if((this->c_text[position] & 0x80) == 0x00) {
		length = 1;
	} else {
		length = 2;
	} 
	if((position + length) > this->c_text.size()) {
		return false;
	}
	this->c_position = position + length;
	return true;
}
