#include "base-tokenizer.h"

bool BaseTokenizer::WriteTokenBuffer(TokenBuffer *token_buffer, string str){
    UTF8Character character;
    int position, length;
    character.SetCharacterText(str);
    while(character.UTF8CharacterLexer(position, length)) {
        string word = str.substr(position, length);
        token_buffer->WriteString(word);
    }
    return true;
}


