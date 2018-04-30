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
