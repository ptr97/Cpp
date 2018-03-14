#pragma once
#include <cstring>
#include "Wrapper.h"

class StringWrapper : public Wrapper
{
public:
	StringWrapper(const char * str);
	virtual void print(std::ostream & os);
	virtual ~StringWrapper();

private:
	char * m_str;
};

StringWrapper::StringWrapper(const char * str)
{
	int strSize = strlen(str);
	
	m_str = new char [strSize + 1];
	strcpy(m_str, str);
}

void StringWrapper::print(std::ostream & os)
{
	os << m_str << " ";
}

StringWrapper::~StringWrapper()
{
	delete [] m_str;
}
