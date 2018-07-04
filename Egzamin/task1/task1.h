#pragma once

#include <iostream>
#include <vector>


class Base
{
public:
	virtual std::ostream & print(std::ostream & os) const = 0;
};

class Derived1 : public Base
{
public:
	virtual std::ostream & print(std::ostream & os) const override
	{
		os << __PRETTY_FUNCTION__ << std::endl;
		return os;
	}
};

class Derived3 : public Base
{
public:
	virtual std::ostream & print(std::ostream & os) const override
	{
		os << __PRETTY_FUNCTION__ << std::endl;
		return os;
	}
};

class Derived2 : public Base
{
public:
	Derived2(const Derived3 &) {}

	virtual std::ostream & print(std::ostream & os) const override
	{
		os << __PRETTY_FUNCTION__ << std::endl;
		return os;
	}
};

std::ostream & operator<<(std::ostream & os, const std::vector<Base *> & vec)
{
	os << "[" << std::endl;

	for(unsigned i = 0; i < vec.size(); ++i)
	{
		vec[i]->print(os);
	}

	os << "]" << std::endl;

	return os;
}

std::ostream & operator<<(std::ostream & os, const Base & base)
{
	return base.print(os);
}
