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

size_t String::size() const
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

bool String::operator==(const String& other) const
{
	if (m_size != other.m_size)
		return false;

	for (int i = 0; i < m_size; i++)
	{
		if (m_buffer[i] != other.m_buffer[i])
			return false;
	}
	return true;
}

bool String::operator==(const char* other) const
{
	if (m_size != strlen(other))
		return false;

	for (int i = 0; i < m_size; i++)
	{
		if (m_buffer[i] != other[i])
			return false;
	}
	return true;
}

bool String::operator!=(const String& other) const
{
	return !operator==(other);
}

bool String::operator!=(const char* other) const
{
	return !operator==(other);
}

bool String::operator<(const String& other) const
{
	size_t min_size = m_size < other.m_size ? m_size : other.m_size;
	for (int i = 0; i < min_size; i++)
	{
		if (m_buffer[i] > other.m_buffer[i])
			return false;
	}
	if (m_size < other.m_size)
		return true;
	return false;
}

bool String::operator<(const char* other) const
{
	size_t other_size = strlen(other);
	size_t min_size = m_size < other_size ? m_size : other_size;
	for (int i = 0; i < min_size; i++)
	{
		if (m_buffer[i] > other[i])
			return false;
	}
	if (m_size < other_size)
		return true;
	return false;
}

bool String::operator<=(const String& other) const
{
	return operator<(other) || operator==(other);
}

bool String::operator<=(const char* other) const
{
	return operator<(other) || operator==(other);
}

bool String::operator>(const String& other) const
{
	if (operator<(other) || operator==(other))
		return false;
	return true;
}

bool String::operator>(const char* other) const
{
	if (operator<(other) || operator==(other))
		return false;
	return true;
}

bool String::operator>=(const String& other) const
{
	return operator>(other) || operator==(other);
}

bool String::operator>=(const char* other) const
{
	return operator>(other) || operator==(other);
}

void String::reverse()
{
	for (int i = 0, n = m_size / 2; i < n; i++)
	{
		char temp = m_buffer[i];
		m_buffer[i] = m_buffer[m_size - 1 - i];
		m_buffer[m_size - 1 - i] = temp;
	}
}

std::ostream& operator<<(std::ostream& stream, const String& s)
{
	stream << s.m_buffer;
	return stream;
}
