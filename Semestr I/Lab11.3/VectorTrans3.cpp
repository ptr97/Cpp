#include "VectorTrans3.h"
#include "Vector3.h"
#include "Number_t.h"


VectorTrans3::VectorTrans3(double x, double y, double z)
{
	m_arr[0] = x;
	m_arr[1] = y;
	m_arr[2] = z;
}

std::ostream & operator<<(std::ostream & os, const VectorTrans3 & vectorTrans)
{
	os << "(";

	for(int i = 0; i < 3; ++i)
	{
		os << vectorTrans.m_arr[i];

		if(i % 3 != 2)
			os << ", ";
		else
			os << ")";
	} 

	return os;
}

number_t VectorTrans3::operator*(const Vector3 & vector) const
{
	double value = 0;

	for(int i = 0; i < 3; ++i)
	{
		value += m_arr[i] * vector.Get(i);
	}

	return number_t(value);
}
