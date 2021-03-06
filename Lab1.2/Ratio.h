#pragma once
#include "Value.h"

class Ratio : public Value
{
public:
	Ratio(Value & prim1, Value & prim2);
	double GetValue() const; 
	void Print() const;
	void PrintWithValue() const; 

private:
	Value * m_a;
	Value * m_b;
};

////////////////////////////////////////////////////////////////////////////////////////////////

Ratio::Ratio(Value & prim1, Value & prim2)
{
	m_a = &prim1;
	m_b = &prim2;
}

double Ratio::GetValue() const
{ 
	return m_a->GetValue() / m_b->GetValue(); 
}

void Ratio::Print() const
{
	std::cout << "(";
	m_a->Print();
	std::cout << "/";
	m_b->Print();
	std::cout << ")";
}

void Ratio::PrintWithValue() const
{
	Print();
	std::cout << " = " << GetValue() << std::endl;
}
