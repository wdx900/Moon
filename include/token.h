#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>

using namespace std;

class Token {
public:
	Token();
	Token(const string &text, int start_offset, int length);
	
	int GetStartOffset() const;
	int GetLength() const;
	
	void SetStartOffset(int start_offset);
	void SetLength(int length);
	void SetText(const string & text);

public:
	bool IsEmpty();
	
public:
	string t_text;
	int t_start_offset;
	int t_length;	
};

inline Token::Token() {
	t_start_offset = -1;
	t_length = 0;
}

inline Token::Token(const string &text, int start_offset, int length):t_text(text) {
	t_start_offset = start_offset;
	t_length = length;
}

inline void Token::SetStartOffset(int start_offset) {
	t_start_offset = start_offset;
}

inline void Token::SetLength(int length) {
	t_length = length;
}

inline void Token::SetText(const string &text) {
	t_text = text;
}

inline int Token::GetStartOffset() const {
	return t_start_offset;	
}

inline int Token::GetLength() const {
	return t_length;
}

inline bool Token::IsEmpty() {
	return t_start_offset == -1;
}

#endif
