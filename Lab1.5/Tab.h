#pragma once
#include <iostream>

class Tab
{
public:
	Tab(const char * name);
	virtual void PrintVal() const {};
	void Print() const;
	virtual ~Tab();
private:
	char * m_name;
};

Tab::Tab(const char * name)
{
	int nameSize = 0;
	while(name[nameSize] != '\0')
		++nameSize;

	m_name = new char [nameSize + 1];

	for(int i = 0; i < nameSize; ++i)
		m_name[i] = name[i];

	m_name[nameSize] = '\0';
}

void Tab::Print() const
{
	std::cout << m_name << ":" << std::endl;
	PrintVal();
}

Tab::~Tab()
{
	delete [] m_name;
}
