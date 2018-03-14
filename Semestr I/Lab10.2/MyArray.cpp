#include "MyArray.h"

#include <iostream>


MyArray::MyArray(int *& array, const int arraySize) : size(m_size), m_array(array)
{
	m_size = arraySize;
	m_copy = m_array;
}

MyArray::MyArray(const MyArray & myArray) : size(m_size), m_array(m_copy)
{
	m_size = myArray.m_size;
	m_ID = myArray.m_ID;

	m_array = new int [m_size];

	for(int i = 0; i < m_size; ++i)
		m_array[i] = myArray.m_array[i];
}

void MyArray::print() const
{
	std::cout << "Content of array with ID=" << m_ID << std::endl;

	for(int i = 0; i < m_size; ++i)
		std::cout << "array[" << i << "] = " << m_array[i] << std::endl;
}

void MyArray::resize(const int newSize)
{
	int * oldArray = m_array;

	m_array = new int [newSize];

	for(int i = 0; i < m_size; ++i)
		m_array[i] = oldArray[i];

	delete [] oldArray;

	m_size = newSize;
}

MyArray::~MyArray()
{
	delete [] m_array;
}
