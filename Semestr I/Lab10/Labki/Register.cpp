#include "Register.h"
#include "ComplexNumber.h"

#include <iostream>

ComplexNumber Register::m_comNum = ComplexNumber();
bool Register::m_ifEmpty = true;
Register * Register::m_regCopy = NULL;

void Register::Clear()
{
	m_ifEmpty = true;
}

Register& Register::Retrieve()
{
	if(!m_regCopy)
		m_regCopy = new Register;

	m_comNum = ComplexNumber();
	std::cout << "Creating register" << std::endl;
	m_ifEmpty = false;

	return *m_regCopy;
}

void Register::Print() const
{
	if(m_ifEmpty)
	{
		std::cout << "Register is empty" << std::endl;
	}
	else
	{
		std::cout << "Register stores number: ";
		m_comNum.Print();
	}
}

void Register::Write(ComplexNumber& comNum)
{
	m_comNum = comNum;
	m_ifEmpty = false;
}

ComplexNumber& Register::Read() const
{
	return m_comNum;
}

Register::~Register()
{
	delete m_regCopy;
}

