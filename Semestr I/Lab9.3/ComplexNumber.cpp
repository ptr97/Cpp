#include "ComplexNumber.h"
#include "ComplexArray.h"

#include <iostream>


ComplexNumber::ComplexNumber(const int real, const int imaginary)
{
	m_real = real;
	m_imaginary = imaginary;
}

ComplexNumber::ComplexNumber(const ComplexNumber & comNum)
{
	m_real = comNum.m_real;
	m_imaginary = comNum.m_imaginary;
}

void ComplexNumber::Print() const
{
	std::cout << m_real << " + " << m_imaginary << "i" << std::endl;
}

ComplexNumber ComplexNumber::Add(const ComplexNumber & comNum)
{
	const int real = m_real + comNum.m_real;
	const int imaginary = m_imaginary + comNum.m_imaginary;

	return ComplexNumber(real, imaginary);
}
