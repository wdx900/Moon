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
	
private:
	string t_text;
	int t_start_offset;
	int t_length;	
};

inline Token() {
	t_start_offset = -1;
	t_length = 0;
}

inline Token(const string &text, int start_offset, int length):t_text(text) {
	t_start_offset = start_offset;
	t_length = length;
}

inline void SetStartOffset(int start_offset) {
	t_start_offset = start_offset;
}

inline void SetLength(int length) {
	t_length = length;
}

inline void SetText(const string &text) {
	t_text = text;
}

inline bool IsEmpty() {
	return t_start_offset == -1;
}

#endif
