#pragma once
#include <iostream>
#include <string>


class SystemObject
{
public:
	SystemObject(const std::string name) : m_name(name) {}
	virtual void print(std::ostream & os, const int spaces) const = 0;
	std::string Name() const {return m_name;}
	virtual ~SystemObject() {}

	friend std::ostream & operator<<(std::ostream & os, const SystemObject & sysObj);

private:
	std::string m_name;
};

std::ostream & operator<<(std::ostream & os, const SystemObject & sysObj)
{
	sysObj.print(os, 0);

	return os;
}