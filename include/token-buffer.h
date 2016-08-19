#ifndef TOKEN_BUFFER_H
#define TOKEN_BUFFER_H

#include "token.h"
#include "buffer-pool.h"
#include <memory>


class TokenBuffer : public BufferPool {

public:
	class Iterator {
		public:
			friend class TokenBuffer;

		private:
			Iterator(TokenBuffer *token_buffer_tmp);
		public:
			~Iterator();
		
		public:
			bool next(Token &token);

		private:
			TokenBuffer *token_buffer;
			Token *token;						
	};

public:	
	TokenBuffer() {};
	virtual ~TokenBuffer() {};
	
	bool WriteToken(const Token &token);
	bool WriteToken(string text);
	bool ReadToken(Token &token);

public:
	Iterator* iterator();

};

typedef auto_ptr<TokenBuffer::Iterator> TokenIterator;

inline TokenBuffer::Iterator::Iterator(TokenBuffer *token_buffer_tmp)
	   :token_buffer(token_buffer_tmp),
		token(NULL) {
}

inline TokenBuffer::Iterator* TokenBuffer::iterator() {
	return new Iterator(this);
}

inline TokenBuffer::Iterator::~Iterator() {
	if(token) {
		delete token;
		token = NULL;
	}
}

inline bool TokenBuffer::Iterator::next(Token &token) {
	if(token_buffer == NULL) {
		return false;
	}
	if(token_buffer->ReadToken(token)) {
		return true;
	} 
	return false;
}

inline bool TokenBuffer::ReadToken(Token &token) {
	if(GetReadCursor(token.t_start_offset) &&
	   ReadString(token.t_text)) {
		return true;
	}
	
	return false;	
} 

inline bool TokenBuffer::WriteToken(string text) {
	if(WriteString(text)) {
		return true;
	}
	return false;
}

#endif
