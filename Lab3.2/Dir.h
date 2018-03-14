#pragma once
#include "SystemObject.h"

class Dir : public SystemObject
{
public:
	Dir(const std::string name) : SystemObject(name), m_size(0) {}
	void operator+=(SystemObject * sysObj);
	void print(std::ostream & os, const int spaces) const;
	SystemObject * get(const std::string name);
	~Dir();

	friend std::ostream & operator<<(std::ostream & os, const Dir & directory);

private:
	SystemObject * m_arr[10];
	int m_size;
};

void Dir::operator+=(SystemObject * sysObj)
{
	m_arr[m_size] = sysObj;
	++m_size;
}

void Dir::print(std::ostream & os, const int spaces) const
{
	for(int i = 0; i < spaces; ++i)
		os << " ";

	os << Name() << std::endl;

	for(int i = 0; i < m_size; ++i)
		m_arr[i]->print(os, spaces + 2);
}

SystemObject * Dir::get(const std::string name)
{
	SystemObject * searched = NULL;

	for(int i = 0; i < m_size; ++i)
	{
		if(m_arr[i]->Name() == name)
			searched = m_arr[i];
	}
	return searched;
}

Dir::~Dir()
{
	std::cout << "Deleting Dir: " << Name() << std::endl;

	for(int i = 0; i < m_size; ++i)
	{
		std::cout << "About to delete " << m_arr[i]->Name() << std::endl;
		delete m_arr[i];
	}
}

std::ostream & operator<<(std::ostream & os, const Dir & directory)
{
	directory.print(os, 0);
	return os;
}

