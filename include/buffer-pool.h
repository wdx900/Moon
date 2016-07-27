#ifndef BUFFER_POOL_H
#define BUFFER_POOL_H

#include <iostream>
using namespace std;


class BufferPool {
public:
	BufferPool();
	virtual ~BufferPool();

public:
	bool WriteString(string &text);
	bool WriteString(const char *text, int length);
	bool WriteInt(const int value);
	bool WriteByte(const char b);
	bool WriteBytes(const void *bytes, int length);

public:
	bool ReadString(string &text);
	bool ReadString(const char *&text, int &length);
	bool ReadInt(const int &value);
	bool ReadByte(const char &b);

public:
	void resize();

private:
	char* b_text;
	char* b_write;
	char* b_read;
	int b_length;

private:
	int write_cursor;
	int read_cursor;

};

inline void BufferPool::resize() {
	b_length *= 2;
}

#endif
