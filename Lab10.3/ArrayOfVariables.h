#pragma once
#include <vector>
#include "Variable.h"


using VariableDouble = Variable<double>;
using VariableFloat = Variable<float>;
using VariableInt = Variable<int>;
using VariableChar = Variable<char>;
using VariableBool = Variable<bool>;


class ArrayOfVariables
{
public:
	ArrayOfVariables(const int size) : m_size(size) {}
	~ArrayOfVariables();

	template <typename Type>
	Variable<Type> * CreateAndAdd(const char * name, const Type val);

	void Print() const;

private:
	const int m_size;
	std::vector<VariableBase *> m_array;
};

ArrayOfVariables::~ArrayOfVariables()
{
	for(VariableBase * varBase : m_array)
		delete varBase;
}

template <typename Type>
Variable<Type> * ArrayOfVariables::CreateAndAdd(const char * name, const Type val)
{
	Variable<Type> * newVariable = new Variable<Type>(name, val);
	m_array.emplace_back(newVariable);
	return newVariable;
}

void ArrayOfVariables::Print() const
{
	for(VariableBase * varBase : m_array)
		varBase->Print();
}