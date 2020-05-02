#include "String.h"
#include <cstring>
#include <iostream>

String::String(const char* s)
{
	m_size = strlen(s);
	m_buffer = new char[m_size + 1];
	memcpy(m_buffer, s, m_size);
	m_buffer[m_size] = 0;	// null-terminating m_buffer
}

String::~String()
{
	delete[] m_buffer;
}

String::String(const String& other)
	: m_size(other.m_size)
{
	m_buffer = new char[m_size + 1];
	memcpy(m_buffer, other.m_buffer, m_size + 1);
}

String& String::operator=(const String& other)
{
	// Handle self-assignment.
	if (this == &other)
		return *this;

	// Free current resources.
	delete[] m_buffer;

	// Copy everything over
	m_size = other.m_size;
	m_buffer = new char[m_size + 1];
	memcpy(m_buffer, other.m_buffer, m_size + 1);

	// Allow assignment chaining.
	return *this;
}

size_t String::Size() const
{
	return m_size;
}

char& String::operator[](unsigned int index)
{
	return m_buffer[index];
}

const char& String::operator[](unsigned int index) const
{
	return m_buffer[index];
}

std::ostream& operator<<(std::ostream& stream, const String& s)
{
	stream << s.m_buffer;
	return stream;
}
