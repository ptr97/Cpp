#pragma once

class ComplexNumber;

class ComplexArray
{
public:
	ComplexArray(const int size);
	ComplexNumber & At(const int index);
	void Set(const int index, const ComplexNumber comNum);
	void Print() const;
	~ComplexArray();

private:
	const int m_arraySize;
	ComplexNumber ** m_comNum;

};
