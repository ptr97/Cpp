#pragma once
#include <string>
#include "Checker.h"

class letterFromRange : public Checker
{
public:
	letterFromRange(const char start, const char end) : m_start(start), m_end(end) {}
	virtual std::string print() const;
	virtual bool match(const std::string expression, int & index) const;
private:
	const char m_start;
	const char m_end;
};

std::string letterFromRange::print() const
{
	std::string expr = "InRange(";
	expr += m_start;
	expr += ",";
	expr += m_end;
	expr += ") ";
	return expr;
}

bool letterFromRange::match(const std::string expression, int & index) const
{
	if(expression[index] >= m_start && expression[index] <= m_end)
	{
		++index;
		return true;
	}
	return false;
	
	// int exprSize = expression.length();
	// bool result = true;

	// for(int i = index; i < exprSize; ++i)
	// {
	// 	if(expression[index] >= m_start && expression[index] <= m_end)
	// 		++index;
	// 	else
	// 		result = false;
	// }
	// return result;
}
