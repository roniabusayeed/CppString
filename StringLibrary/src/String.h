#pragma once

#include <iostream>

class String
{
private:
	size_t m_size;
	char* m_buffer;

	friend std::ostream& operator<<(std::ostream& stream, const String& s);
public:
	String();
	String(const char* s);
	~String();
	String(const String& other);
	String& operator=(const String& other);
	size_t size()const;
	char& operator[](unsigned int index);
	const char& operator[](unsigned int index) const;
	bool operator==(const String& other)const;
	bool operator==(const char* other)const;
	bool operator!=(const String& other)const;
	bool operator!=(const char* other)const;
	bool operator<(const String& other)const;
	bool operator<(const char* other)const;
	bool operator<=(const String& other)const;
	bool operator<=(const char* other)const;
	bool operator>(const String& other)const;
	bool operator>(const char* other)const;
	bool operator>=(const String& other)const;
	bool operator>=(const char* other)const;
	void reverse();
	void append(const String& other);
	void append(const char* other);
	String operator+(const String& other)const;
	String operator+(const char* other)const;
	void insert(size_t off, char c);
};