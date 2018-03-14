#include "SlopeFit.h"

SlopeFit::SlopeFit()
{
	int size = 2;
	m_arr = new double [size];
	for (int i = 0; i < size; ++i)
		m_arr[i] = 0;
}

void SlopeFit::appendPoint(const double x, const double y)
{
	m_arr[0] += x * y;
	m_arr[1] += x * x;
}

Fit & SlopeFit::result()
{
	return *this;
}

char * SlopeFit::expression() const
{
	return "y = a * x";
}

unsigned SlopeFit::nParams() const
{
	return 1;
}

char SlopeFit::parameterName(const int i) const 
{
	return 'a';
}

double SlopeFit::parameterValue(const int i) const
{
	return m_arr[0] / m_arr[1];
}

SlopeFit::~SlopeFit()
{
	delete [] m_arr;
}
