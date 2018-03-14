#pragma once 

class Register;

class ComplexNumber
{
public:
	ComplexNumber(const int real, const int imaginary);
	void Print() const;
	ComplexNumber& SetReal(const int real);
	ComplexNumber& SetImaginary(const int imaginary);
	void Save(Register& reg) const;
	ComplexNumber Add(const ComplexNumber& comNum) const;
	int Real() const {return m_real;};
	int Imaginary() const {return m_imaginary;};
	~ComplexNumber();

private:
	int m_real;
	int m_imaginary;
};
