#include "Register.h"
#include "ComplexNumber.h"

#include <iostream>


ComplexNumber * Register::m_comNum = NULL;
Register * Register::m_reg = NULL;


void Register::Clear()
{
	if(m_comNum)
		delete m_comNum;

	if(m_reg)
		delete m_reg;
}

Register& Register::Retrieve()
{
	if(!m_reg)
	{
		std::cout << "Creating register" << std::endl;
		m_reg = new Register;
	}
	
	return * m_reg;
}

void Register::Print() const
{
	if(!m_comNum)
		std::cout << "Register is empty" << std::endl;
	else
	{
		std::cout << "Register stores number: ";
		(*m_comNum).ComplexNumber::Print();
	}
}

void Register::Write(ComplexNumber& comNum)
{
	if(!m_comNum)
		m_comNum = new ComplexNumber(comNum.Real(), comNum.Imaginary());

	else
		*m_comNum = ComplexNumber(comNum);
}

ComplexNumber& Register::Read() const
{
	return * m_comNum;
}

