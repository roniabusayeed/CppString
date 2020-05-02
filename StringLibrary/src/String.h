#pragma once

class String
{
private:
	size_t m_size;
	char* m_buffer;
public:
	String(const char* s);
	~String();
	String(const String& other);
	String& operator=(const String& other);
};