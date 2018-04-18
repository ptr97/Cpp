#pragma once
#include <iostream>


namespace Executor
{

class Function
{
public:
	virtual double operator()(double x) const = 0;
	virtual ~Function() {}
};


class Result
{
public:
	Result(const double val = 0) : value(val) {} 
	operator double() const;

	double value;
	bool valid = false;
};

Result secureRun(const Function & fun, const double x);

}

std::ostream & operator<<(std::ostream & os, const Executor::Result & res);
