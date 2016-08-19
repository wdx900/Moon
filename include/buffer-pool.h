#ifndef BUFFER_POOL_H
#define BUFFER_POOL_H

#include <iostream>
#include <string.h>

using namespace std;

#define INIT_POOL_SIZE 1024

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
	bool ReadInt(int &value);
	bool ReadByte(char &b);	
	bool ReadBytes(void* bytes, int length);

public:
	bool GetPool(char* byte);
	bool GetWriteSize(int size);
	bool GetReadCursor(int cursor);

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

inline bool BufferPool::GetWriteSize(int size) {
	size = write_cursor;
	return true;
}

inline bool BufferPool::GetReadCursor(int cursor) {
	cursor = read_cursor;
	return true;
}


#endif
