#pragma once
#include <string>

class Checker
{
public: 
	virtual std::string print() const = 0;
	virtual bool match(const std::string expression, int & index) const = 0;
	virtual ~Checker() {}
};
