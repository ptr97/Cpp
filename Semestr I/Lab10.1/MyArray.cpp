#include "MyArray.h"

#include <iostream>


MyArray::MyArray(const int arraySize) : size(m_size), m_size(arraySize)
{
	m_array = new int [m_size];
}

MyArray::MyArray(const MyArray& myArray) : size(m_size), m_size(myArray.size)
{
	m_array = new int [m_size];

	for(int i = 0; i < m_size; ++i)
		m_array[i] = myArray.at(i);
}

int & MyArray::at(const int index)
{
	return m_array[index];
}

int MyArray::at(const int index) const
{
	return m_array[index];
}

void MyArray::print() const
{
	std::cout << "Array content:" << std::endl;

	for(int i = 0; i < m_size; ++i)
	{
		std::cout << "array[" << i << "] = " << m_array[i] << std::endl;
	}
}

void MyArray::resize(const int newSize)
{
	int * newArray = new int [newSize];

	for(int i = 0; i < m_size; ++i)
		newArray[i] = m_array[i];

	m_size = newSize;

	delete [] m_array;
	m_array = newArray;
}

MyArray::~MyArray()
{
	delete [] m_array;
}
