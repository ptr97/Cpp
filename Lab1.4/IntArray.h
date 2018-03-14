#pragma once
#include "Element.h"

class IntArray : public Element
{
public:
	IntArray(const int size);
	IntArray(const IntArray & iArr);
	virtual void Print() const;
	int & operator[](const int i);
	virtual ~IntArray();

private:
	int * m_arr;
	int m_size;
};

IntArray::IntArray(const int size) : m_size(size)
{
	m_arr = new int[m_size];
}

IntArray::IntArray(const IntArray & iArr) : m_size(iArr.m_size)
{
	m_arr = new int[m_size];

	for(int i = 0; i < m_size; ++i)
		m_arr[i] = iArr.m_arr[i];
}

void IntArray::Print() const
{
	std::cout << "IntArray: (";
	for(int i = 0; i < m_size; ++i)
	{
		std::cout << m_arr[i];
		if(m_size - i != 1)
			std::cout << ", ";
	}
	std::cout << ")" << std::endl;
}

int & IntArray::operator[](const int i)
{
	return m_arr[i];
}

IntArray::~IntArray()
{
	delete [] m_arr;
}
