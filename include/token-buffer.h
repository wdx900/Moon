#ifndef TOKEN_BUFFER_H
#define TOKEN_BUFFER_H

#include "token.h"

class TokenBuffer {

public:
	class Iterator {
		public:
			friend class TokenBuffer;

		public:
			Iterator();
		public:
			~Iterator();
		
		public:
			bool next(Token &token);

		private:
			TokenBuffer *token_buffer;
			Token *token;						
	};

public:	
	TokenBuffer();
	virtual ~TokenBuffer();
	
	bool WriteToken(const Token &token);		
	bool ReadToken(Token &token);
};

inline bool TokenBuffer::Iterator::next(Token &token) {
	if(token_buffer == NULL) {
		return false;
	}
	if(token_buffer->ReadToken(token)) {
		return true;
	} 
	return false;
}



#endif
