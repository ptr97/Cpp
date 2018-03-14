#include "Number.h"
#include <iostream>

Number * Number::NumFactory(const int value)
{
	Number * ptr = new Number(value);

	return ptr;
}

void Number::Print() const
{
	std::cout << "This is number: " << m_value << std::endl;
}

Number::Number(const int value)
{
	m_value = value;

	std::cout << "Creating number: " << m_value << std::endl;
}

Number::~Number()
{
	std::cout << "Destroying number: " << m_value << std::endl;
}

