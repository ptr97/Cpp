#pragma once
#include <vector>
#include "Fibonaci.h"


class Array
{
public:
	~Array();
	void push_back(Fibo * fibonaci);
	void print() const;
	Fibo * operator[](const int index) const;
private:
	std::vector<Fibo *> m_array;
};

Array::~Array()
{
	for(Fibo * f : m_array)
		delete f;
}

void Array::push_back(Fibo * fibonaci)
{
	m_array.emplace_back(fibonaci);
}

void Array::print() const
{
	for(Fibo * f : m_array)
		f->print();
}

Fibo * Array::operator[](const int index) const
{
	return m_array[index];
}
