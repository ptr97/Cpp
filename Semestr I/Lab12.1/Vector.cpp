#include "Vector.h"


Vector::Vector(const int size)
{
	m_size = size;
	m_arr = new int [m_size];
}

Vector::Vector(const Vector & vec)
{
	m_size = vec.m_size;
	m_arr = new int [m_size];

	for(int i = 0; i < m_size; ++i)
		m_arr[i] = vec.m_arr[i];
}

Vector::~Vector()
{
	if(m_arr)
		delete [] m_arr;
}

int & Vector::operator[](const int index)
{
	return m_arr[index];
}

int Vector::operator[](const int index) const
{
	return m_arr[index];
}

std::ostream & operator<<(std::ostream & os, const Vector & vec)
{
	os << "[";

	for(int i = 0; i < vec.m_size; ++i)
	{
		os << vec.m_arr[i];

		if(i % vec.m_size != vec.m_size - 1)
			os << ", ";
	}
	os << "]";

	return os;
}

double operator*(const Vector & vec, const VectorTrans & vecTrans)
{
	double result = 0;

	for(int i = 0; i < vec.m_size; ++i)
	{
		result += vec.m_arr[i] * vecTrans.m_arr[i];
	}

	return result;
}	

Vector & Vector::operator=(const Vector & vec)
{
	if(&vec == this)
		return *this;

	if(m_arr)
		delete [] m_arr;

	m_size = vec.m_size;
	m_arr = new int [m_size];

	for(int i = 0; i < m_size; ++i)
		m_arr[i] = vec.m_arr[i];

	return *this;
}
