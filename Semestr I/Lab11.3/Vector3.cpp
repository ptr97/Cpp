#include "Vector3.h"
#include "VectorTrans3.h"
#include "Matrix3.h"
#include "Hello.h"

Hello Vector3::hey = Hello();

Vector3::Vector3(double x, double y, double z)
{
	m_arr[0] = x;
	m_arr[1] = y;
	m_arr[2] = z;
}

std::ostream & operator<<(std::ostream & os, const Vector3 & vector)
{
	for(int i = 0; i < 3; ++i)
	{
		os << "(" << vector.m_arr[i] << ")";

		if(i % 3 != 2)
			os << std::endl;
	}

	return os;
}

Matrix3 Vector3::operator*(const VectorTrans3 & vectorTrans) const
{
	double arr[3][3] = {0};

	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			arr[i][j] = m_arr[i] * vectorTrans.Get(j);
		}
	}

	return Matrix3(arr, 3);
}

