#pragma once
#include <iostream>

class Element
{
public:
	virtual void Print() const = 0;
	virtual ~Element() {};
};

void Element::Print() const
{
	std::cout << "Element" << std::endl;
}