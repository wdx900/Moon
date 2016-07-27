#include "base-character.h"

bool BaseCharacter::SetCharacterText(const string &text) {
	this->c_text = text;
	this->c_position = 0;
	return true;
}
