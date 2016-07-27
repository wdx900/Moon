#include "buffer-pool.h"

bool BufferPool::WriteByte(const char b) {
	if(this->write_cursor + 1 > this->b_length) {
		resize();
	}
	*this->b_write = b;
	++this->write_cursor;
	++this->b_write;
	return true;
}

bool BufferPool::WriteBytes(const void *bytes, int length) {
	if(length == 0) {
		return true;
	}
	while(this->write_cursor + length > this->b_length) {
		resize();
	}
	memcpy(this->b_write, bytes, length);
	b_write += length;
	write_cursor += length;
	return true;
}

bool BufferPool::WriteInt(const int value) {
	WriteBytes((void *))
}

bool BufferPool::WriteString(const char *text, int length) {
	
	return WriteBytes(text, length);	
}

