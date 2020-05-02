#include "String.h"
#include <cstring>

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
