#include "Verifier.h"


std::ostream & operator<<(std::ostream & os, const ArgVerificationFailed & avf)
{
	os << avf.m_error;
	return os;
}


void is::operator<=(const int toValidate) const
{
	if(!(m_value <= toValidate))
	{
		std::string error = "Argument ";
		error += std::to_string(m_value);
		error += " has to be lower or equal than ";
		error += std::to_string(toValidate);
		
		throw ArgVerificationFailed(error);
	}
}

void is::operator<(const int toValidate) const
{
	if(!(m_value < toValidate))
	{
		std::string error = "Argument ";
		error += std::to_string(m_value);
		error += " has to be lower than ";
		error += std::to_string(toValidate);
		
		throw ArgVerificationFailed(error);
	}
}

void is::operator>=(const int toValidate) const
{
	if(!(m_value >= toValidate))
	{
		std::string error = "Argument ";
		error += std::to_string(m_value);
		error += " has to be greater or equal than ";
		error += std::to_string(toValidate);
		
		throw ArgVerificationFailed(error);
	}
}

void is::operator>(const int toValidate) const
{
	if(!(m_value > toValidate))
	{
		std::string error = "Argument ";
		error += std::to_string(m_value);
		error += " has to be greater than ";
		error += std::to_string(toValidate);
		
		throw ArgVerificationFailed(error);
	}
}
