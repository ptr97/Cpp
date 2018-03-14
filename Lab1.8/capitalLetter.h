#pragma once
#include <string>
#include "Checker.h"

class capitalLetter : public Checker
{
public:
	virtual std::string print() const;
	virtual bool match(const std::string expression, int & index) const;
};


std::string capitalLetter::print() const
{
	return "CapitalLetter() ";
}

bool capitalLetter::match(const std::string expression, int & index) const
{
	if(expression[index] >= 'A' && expression[index] <= 'Z')
	{
		++index;
		return true;
	}
	return false;
}	
