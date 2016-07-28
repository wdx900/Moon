#include "buffer-pool.h"

BufferPool::BufferPool()
	: write_cursor(0)
	, read_cursor(0)
	, b_length(INIT_POOL_SIZE) {
	
	b_pool = new char[b_length];
	b_write = b_pool;
	b_read = b_pool;	
		
}

BufferPool::~BufferPool() {
	if(b_pool) {
		delete [] b_pool;
	}
	b_pool = NULL;
	b_write = NULL;
	b_read = NULL;
}

void BufferPool::resize() {
	int new_length = (b_length << 1);
	char* new_pool = new char[new_length];
	memcpy(new_pool, b_pool, b_length);
	delete [] b_pool;	

	b_length = new_length;
	b_pool = new_pool;
	b_write = b_pool;
	b_read = b_pool;
	b_write += write_cursor;
	b_read += read_cursor;
}

bool BufferPool::WriteByte(const char b) {
	if(this->write_cursor + 1 > this->b_length) {
		resize();
	}
	this->b_write[0] = b;
	++(this->write_cursor);
	++(this->b_write);
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
	this->b_write += length;
	this->write_cursor += length;
	return true;
}

bool BufferPool::WriteInt(const int value) {
	return WriteBytes((void *) &value, sizeof(int));
}

bool BufferPool::WriteString(const char *text, int length) {
	WriteInt(length);
	WriteBytes(text, length);	
	return true;
}

bool BufferPool::WriteString(const string &text) {
	WriteInt(text.size());
	WriteString(text.c_str(), text.size());
	return true;
}

bool BufferPool::ReadByte(char &b) {
	if(this->read_cursor >= this->b_length) {
		return false;
	}
	b = *this->b_read;
	++this->read_cursor;
	++this->b_read;
}

bool BufferPool::ReadBytes(void* bytes, int length) {
	if(length == 0) {
		return true;
	}
	if(this->read_cursor + length > this->b_length) {
		return false;
	}
	memcpy(bytes, this->b_read, length);
	b_read += length;
	read_cursor += length;
	return true;
}

bool BufferPool::ReadInt(int &value) {
	void * v = &value;
	return ReadBytes(v , sizeof(int));
}

bool BufferPool::ReadString(char *text, int &length) {
	if(!ReadInt(length) || length < 0) {
		return false;
	}
	text = new char[length + 1];
	ReadBytes(text, length);
	text[length] = '\0';
	return true;
}

bool BufferPool::GetPool(char* byte) {
	if(b_pool) {
		byte = b_pool;
	}	
	return true;
} 




