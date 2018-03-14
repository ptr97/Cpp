#pragma once
#include "Element.h"

class FloatArray : public Element
{
public:
	FloatArray(const int size);
	FloatArray(const FloatArray & fArr);
	virtual void Print() const;
	float & operator[](const int i);
	virtual ~FloatArray();

private:
	float * m_arr;
	int m_size;
};

FloatArray::FloatArray(const int size) : m_size(size)
{
	m_arr = new float[m_size];
}

FloatArray::FloatArray(const FloatArray & fArr) : m_size(fArr.m_size)
{
	m_arr = new float[m_size];

	for(int i = 0; i < m_size; ++i)
		m_arr[i] = fArr.m_arr[i];
}

void FloatArray::Print() const
{
	std::cout << "FloatArray: (";
	for(int i = 0; i < m_size; ++i)
	{
		std::cout << m_arr[i];
		if(m_size - i != 1)
			std::cout << ", ";
	}
	std::cout << ")" << std::endl;
}

float & FloatArray::operator[](const int i)
{
	return m_arr[i];
}

FloatArray::~FloatArray()
{
	delete [] m_arr;
}
