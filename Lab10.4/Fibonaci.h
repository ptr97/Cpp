#pragma once
#include <iostream>


class Fibo
{
public:
	virtual void print() const = 0; 
	virtual ~Fibo() {}
};


template <int x>
class Fibonaci : public Fibo
{
public:
	enum {value = Fibonaci<x - 1>::value + Fibonaci<x - 2>::value};

	virtual void print() const override
	{
		std::cout << "Fibonaci(" << x << ") = " << value << std::endl;
	}
};


template <> 
class Fibonaci<1> : public Fibo
{
public:
	enum {value = 1};

	virtual void print() const override
	{
		std::cout << "Fibonaci(" << 1 << ") = " << value << std::endl;
	}
};


template <> 
class Fibonaci<2> : public Fibo
{
public:
	enum {value = 1};

	virtual void print() const override
	{
		std::cout << "Fibonaci(" << 2 << ") = " << value << std::endl;
	}
};