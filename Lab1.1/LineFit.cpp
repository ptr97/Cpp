#include "LineFit.h"

LineFit::LineFit()
{
	m_nPoints = 0;
	
	int size = 4;
	m_arr = new double [size];
	for (int i = 0; i < size; ++i)
		m_arr[i] = 0;
}

void LineFit::appendPoint(const double x, const double y)
{
	++m_nPoints;
	
	m_arr[0] += x * y;
	m_arr[1] += x * x;
	m_arr[2] += x;
	m_arr[3] += y;
}

Fit & LineFit::result()
{
	return *this;
}

char * LineFit::expression() const
{
	return "y = a * x + b";
}

unsigned LineFit::nParams() const
{
	return 2;
}

char LineFit::parameterName(const int i) const 
{
	
	if(i == 0)
		return 'a';
	else 
		return 'b';
}

double LineFit::parameterValue(const int i) const
{
	// a = (suma xi yi -  suma xi * suma yi / N)/(suma xi xi - suma xi * suma xi/N)
   	// b = (suma yi -a suma xi)/N
	double a = (m_arr[0] - m_arr[2] * m_arr[3] / m_nPoints) / (m_arr[1] - m_arr[2] * m_arr[2] / m_nPoints);
	if(i == 0)
		return a;
	else 
		return (m_arr[3] - a * m_arr[2]) / m_nPoints;
}

LineFit::~LineFit()
{
	delete [] m_arr;
}
