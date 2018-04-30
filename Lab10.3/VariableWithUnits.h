#pragma once
#include <string>
#include "Variable.h"


template <typename Type>
class VariableWithUnits : public Variable<Type>
{
public:
	VariableWithUnits<Type>(const char * name, const Type value, const char * units) :
							Variable<Type>(name, value), m_units(units) {}

	virtual void Print() const override;

private:
	std::string m_units;
};


template <typename Type>
void VariableWithUnits<Type>::Print() const
{
	Variable<Type>::PrintAtributes();
	std::cout << " [" << m_units << "]" << std::endl;
}
