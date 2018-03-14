#pragma once 

class ComplexNumber;

class Register
{
public:
	static void Clear();
	static Register& Retrieve();
	void Print() const;
	void Write(ComplexNumber& comNum);
	ComplexNumber& Read() const;
	ComplexNumber*& ComNum() {return m_comNum;};

private:
	static ComplexNumber * m_comNum;
	static Register * m_reg;
};
