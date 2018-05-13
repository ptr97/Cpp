#pragma once

#include <stdexcept>
#include <iostream>
#include "X.h"


template <int size, typename Type>
class Array
{
public:
	Array() {}
	~Array() {}

	Type & operator[](const int index);

	friend std::ostream & operator<<(std::ostream & os, Array<size, Type> & array);


private:
	Type m_array[size];
};


template <int size, typename Type>
Type & Array<size, Type>::operator[](const int index)
{
	if(index >= size)
		throw std::invalid_argument("Indeks poza zakresem");
	return m_array[index];
}

template <>
Array<7, int>::Array()
{
	for(int i = 0; i < 7; ++i)
		m_array[i] = 0;
}

template <>
Array<5, X*>::Array()
{
	for(int i = 0; i < 5; ++i)
		m_array[i] = nullptr;
}

template <>
Array<5, X*>::~Array()
{
	for(int i = 0; i < 5; ++i)
		delete m_array[i];
}

template <>
X* & Array<5, X*>::operator[](const int index)
{
	if(index >= 5)
		throw std::invalid_argument("Indeks poza zakresem");
	return m_array[index];
}

std::ostream & operator<<(std::ostream & os, Array<7, int> & array)
{
	for(int i = 0; i < 7; ++i)
		os << array[i] << " ";
	return os;
}

std::ostream & operator<<(std::ostream & os, Array<4, X> & array)
{
	for(int i = 0; i < 4; ++i)
		os << array[i] << " ";
	return os;
}

std::ostream & operator<<(std::ostream & os, Array<5, X*> & array)
{
	for(int i = 0; i < 5; ++i)
	{
		if(array[i])
			os << *array[i] << " ";
	}
	return os;
}
