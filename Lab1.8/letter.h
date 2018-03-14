#pragma once
#include <string>
#include "Checker.h"

class letter : public Checker
{
public:
	letter(const char c) : m_char(c) {}
	virtual std::string print() const;
	virtual bool match(const std::string expression, int & index) const;
private:
	const char m_char;
};

std::string letter::print() const
{
	std::string expr = "Letter(";
	expr += m_char;
	expr += ") ";
	return expr;
}

bool letter::match(const std::string expression, int & index) const
{
	if(expression[index] == m_char)
	{
		++index;
		return true;
	}
	return false;
}
