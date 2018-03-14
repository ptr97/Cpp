#include "VectorTrans.h"


VectorTrans::VectorTrans(const int size)
{
	m_size = size;
	m_arr = new int [m_size];
}

VectorTrans::~VectorTrans()
{
	if(m_arr)
		delete [] m_arr;
}

int & VectorTrans::operator[](const int index)
{
	return m_arr[index];
}

int VectorTrans::operator[](const int index) const
{
	return m_arr[index];
}

std::ostream & operator<<(std::ostream & os, const VectorTrans & vecTrans)
{
	for(int i = 0; i < vecTrans.m_size; ++i)
		os << "[" << vecTrans.m_arr[i] << "]" << std::endl;

	return os;
}

Matrix operator*(const VectorTrans & vecTrans, const Vector & vec)
{
	int ** array = new int * [vecTrans.m_size];
	for(int i = 0; i < vecTrans.m_size; ++i)
		array[i] = new int [vec.m_size];

	for(int i = 0; i < vecTrans.m_size; ++i)
	{
		for(int j = 0; j < vec.m_size; ++j)
		{
			array[i][j] = vecTrans.m_arr[i] * vec.m_arr[j];
		}
	}

	return Matrix(&array, vecTrans.m_size);
}

