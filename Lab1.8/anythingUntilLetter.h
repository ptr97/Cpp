#pragma once
#include <string>
#include "Checker.h"

class anythingUntilLetter : public Checker
{
public:
	anythingUntilLetter(const char c) : m_char(c) {}
	virtual std::string print() const;
	virtual bool match(const std::string expression, int & index) const;
private:
	const char m_char;
};

std::string anythingUntilLetter::print() const
{
	std::string expr = "UntilLetter(";
	expr += m_char;
	expr += ") ";
	return expr;
}

bool anythingUntilLetter::match(const std::string expression, int & index) const
{
	int exprSize = expression.length();
	bool result = false;

	for(int i = index; i < exprSize; ++i)
	{
		if(expression[i] != m_char)
			++index;
		else
		{
			result = true;
			++index;
			break;
		}
	}
	return result;
}
