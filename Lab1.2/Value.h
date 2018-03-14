#pragma once
#include <iostream>

class Value
{
public:
	virtual void Print() const  = 0 ;
	virtual void PrintWithValue() const = 0;
	virtual double GetValue() const = 0;
};
