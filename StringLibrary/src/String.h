#pragma once

#include <iostream>

class String
{
private:
	size_t m_size;
	char* m_buffer;

	friend std::ostream& operator<<(std::ostream& stream, const String& s);
public:
	String(const char* s);
	~String();
	String(const String& other);
	String& operator=(const String& other);
	size_t Size()const;
	char& operator[](unsigned int index);
	const char& operator[](unsigned int index) const;
	bool operator==(const String& other)const;
	bool operator==(const char* other)const;
	bool operator<(const String& other)const;
	bool operator<(const char* other)const;
};