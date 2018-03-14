#pragma once
#include "Value.h"

class Primitive : public Value
{
public:
	Primitive(const double val);
	void Set(const double val);
	double GetValue() const;
	void Print() const;
	void PrintWithValue() const {};

private:
	double m_val;
};

////////////////////////////////////////////

Primitive::Primitive(const double val)
{
	m_val = val;
}

void Primitive::Set(const double val)
{
	m_val = val;
}

double Primitive::GetValue() const
{
	return m_val;
}

void Primitive::Print() const
{
	std::cout << m_val;
}
