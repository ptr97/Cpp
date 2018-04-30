#pragma once
#include <iostream>
#include <string>
#include "VariableBase.h"


template <typename Type>
class Variable : public VariableBase
{
public:
	Variable<Type>(const char * name, const Type value) : m_value(value) {m_name = name;}
	virtual void Print() const override;
	virtual void PrintAtributes() const;
	void SetValue(const Type newValue);

private:
	Type m_value;
};

template <typename Type>
void Variable<Type>::Print() const
{
	PrintAtributes();
	std::cout << std::endl;
}

template <typename Type>
void Variable<Type>::PrintAtributes() const
{
	std::cout << m_name << ": " << m_value;;
}

template <typename Type>
void Variable<Type>::SetValue(const Type newValue)
{
	m_value = newValue;
}
