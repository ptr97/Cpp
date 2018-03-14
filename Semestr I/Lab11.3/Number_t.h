#pragma once 
#include <iostream>


class number_t
{
public:
	number_t(const double num) : m_value(num) {} ;
	friend std::ostream & operator<<(std::ostream & os, const number_t & number);

private:
	double m_value;
};
