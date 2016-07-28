#ifndef BUFFER_POOL_H
#define BUFFER_POOL_H

#include <iostream>
#include <string.h>

using namespace std;

#define INIT_POOL_SIZE 102400

class BufferPool {
public:
	BufferPool();
	virtual ~BufferPool();

public:
	bool WriteString(const string &text);
	bool WriteString(const char* text, int length);
	bool WriteInt(const int value);
	bool WriteByte(const char b);
	bool WriteBytes(const void* bytes, int length);

public:
	bool ReadString(string &text);
	bool ReadString(char* text, int &length);
	bool ReadInt(int &value);
	bool ReadByte(char &b);	
	bool ReadBytes(void* bytes, int length);

public:
	bool GetPool(char* byte);

private:
	void resize();

private:
	char* b_pool;
	char* b_read;
	char* b_write;
	int b_length;
	

private:
	int write_cursor;
	int read_cursor;

};

#endif
