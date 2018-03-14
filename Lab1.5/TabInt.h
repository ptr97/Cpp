#pragma once
#include "Tab.h"

class TabInt : virtual public Tab
{
public:
	TabInt(const char * name, const int size);
	void Set(const int index, const int value);
	void PrintName() const;
	void PrintVal() const;
	virtual ~TabInt();
	
private:
	int m_size;
	int * m_tab;
};

TabInt::TabInt(const char * name, const int size) : Tab(name)
{
	m_size = size;
	m_tab = new int [m_size];
}

void TabInt::Set(const int index, const int value)
{
	m_tab[index] = value;
}

void TabInt::PrintName() const
{
	Tab::Print();
}

void TabInt::PrintVal() const
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

TabInt::~TabInt()
{
	delete [] m_tab;
}