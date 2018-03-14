#pragma once
#include "Value.h"

class Sum : public Value
{
public:
	Sum(Value & prim1, Value & prim2);
	double GetValue() const; 
	void Print() const;
	void PrintWithValue() const;

private:
	Value * m_a;
	Value * m_b;
};

////////////////////////////////////////////////////////////////////////////////////////////////

Sum::Sum(Value & prim1, Value & prim2)
{
	m_a = &prim1;
	m_b = &prim2;
}

double Sum::GetValue() const
{ 
	return m_a->GetValue() + m_b->GetValue(); 
}

void Sum::Print() const
{
	std::cout << "(";
	m_a->Print();
	std::cout << "+";
	m_b->Print();
	std::cout << ")";
}

void Sum::PrintWithValue() const
{
	Print();
	std::cout << " = " << GetValue() << std::endl;
}
