#include "ComplexArray.h"
#include "ComplexNumber.h"

#include <iostream>

ComplexArray::ComplexArray(const int size) : m_arraySize(size)
{
	m_comNum = new ComplexNumber * [size];

	for(int i = 0; i < m_arraySize; ++i)
		m_comNum[i] = new ComplexNumber(0, 0);
}

ComplexNumber & ComplexArray::At(const int index)
{
	return *(m_comNum[index]);
}

void ComplexArray::Set(const int index, const ComplexNumber comNum)
{
	*(m_comNum[index]) = comNum;
}

void ComplexArray::Print() const
{
	std::cout << "Array:" << std::endl;

	for(int i = 0; i < m_arraySize; ++i)
	{
		std::cout << i + 1 << ": ";
		(*(m_comNum[i])).ComplexNumber::Print();
	}
}

ComplexArray::~ComplexArray()
{
	for(int i = 0; i < m_arraySize; ++i)
		delete m_comNum[i];

	delete [] m_comNum;
}

