#include "Matrix3.h"


Matrix3::Matrix3(double arr[][3], const int columns)
{
	for(int i = 0; i < columns; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			m_arr[i][j] = arr[i][j];
		}
	}
}

std::ostream & operator<<(std::ostream & os, const Matrix3 & matrix)
{
	for(int i = 0; i < 3; ++i)
	{
		os << "(";

		for(int j = 0; j < 3; ++j)
		{
			os << matrix.m_arr[i][j];

			if(j % 3 != 2)
				os << ", ";
			else
				os << ")";
		}

		os << std::endl;
	}

	return os;
}
