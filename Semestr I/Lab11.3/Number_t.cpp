#include "Number_t.h"


std::ostream & operator<<(std::ostream & os, const number_t & number)
{
	os << number.m_value << std::endl;

	return os;
}
