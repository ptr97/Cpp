#pragma once

class ComplexNumber
{
public:
	//konstruktor klasy ComplexNumber, inicjalizuje skladowe klasy
	ComplexNumber(const int real, const int imaginary = 0);
	ComplexNumber(const ComplexNumber & comNum);
	void Print() const; 
	// int Real() const {return m_real;};
	// int Imaginary() const {return m_imaginary;};
	ComplexNumber Add(const ComplexNumber & comNum);
	

private:
	int m_real;
	int m_imaginary;
};
