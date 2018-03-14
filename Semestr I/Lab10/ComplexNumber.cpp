#include "ComplexNumber.h"
#include "Register.h"

#include <iostream>

ComplexNumber::ComplexNumber(const int real, const int imaginary)
{
	m_real = real;
	m_imaginary = imaginary;

	std::cout << "Creating number: " << m_real << " + " << m_imaginary << "i" << std::endl;
}

void ComplexNumber::Print() const
{
	std::cout << m_real << " + " << m_imaginary << "i" << std::endl;
}

ComplexNumber& ComplexNumber::SetReal(const int real)
{
	m_real = real;

	return *this;
}

ComplexNumber& ComplexNumber::SetImaginary(const int imaginary)
{
	m_imaginary = imaginary;

	return *this;
}

void ComplexNumber::Save(Register& reg) const
{
	if(reg.ComNum())
		*(reg.ComNum()) = ComplexNumber(*this);
	else
		reg.ComNum() = new ComplexNumber(*this);
}

ComplexNumber ComplexNumber::Add(const ComplexNumber& comNum) const
{
	const int real = m_real + comNum.m_real;
	const int imaginary = m_imaginary + comNum.m_imaginary;

	return ComplexNumber(real, imaginary);
}

ComplexNumber::~ComplexNumber()
{
	std::cout << "Deleting: " << m_real << " + " << m_imaginary << "i" << std::endl;
}
