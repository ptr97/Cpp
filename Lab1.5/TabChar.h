#pragma once
#include "Tab.h"

class TabChar : virtual public Tab
{
public:
	TabChar(const char * name, const int size);
	void Set(const int index, const char value);
	void PrintName() const;
	void PrintVal() const;
	virtual ~TabChar();

private:
	int m_size;
	char * m_tab;
};


TabChar::TabChar(const char * name, const int size) : Tab(name)
{
	m_size = size;
	m_tab = new char [m_size];
}

void TabChar::Set(const int index, const char value)
{
	m_tab[index] = value;
}

void TabChar::PrintName() const
{
	Tab::Print();
}

void TabChar::PrintVal() const
{
	std::cout << "(";

	for(int i = 0; i < m_size; ++i)
	{
		std::cout << m_tab[i];
		if(m_size - i != 1)
			std::cout << ", ";
	}

	std::cout << ")" << std::endl;
}	

TabChar::~TabChar()
{
	delete [] m_tab;
}
