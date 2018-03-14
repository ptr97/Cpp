#pragma once
#include "Element.h"


class Number : public Element
{
public:
	Number(const float num) : m_num(num) {};
	virtual void Print() const;
private:
	const float m_num;
};

void Number::Print() const
{
	std::cout << "Number: " << m_num << std::endl;
}