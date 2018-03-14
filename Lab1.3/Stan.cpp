#include "Stan.h"
#include <cstring>
#include <iostream>

Stan::Stan(const char * name)
{
	int size = 0;
	while(name[size] != '\0')
		++size;

	m_name = new char [size + 1];
	strcpy(m_name, name);
}

void Stan::Print() const
{
	std::cout << m_name;
}

Stan::~Stan()
{
	delete [] m_name;
}
