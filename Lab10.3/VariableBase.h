#pragma once
#include <string>


class VariableBase
{
public:
	virtual void Print() const = 0;
	virtual ~VariableBase() {}

protected:
	std::string m_name;
};

