#pragma once
#include "Wrapper.h"

class IntWrapper : public Wrapper
{
public:
	IntWrapper(const int value) : m_val(value) {}
	virtual void print(std::ostream & os);
	virtual ~IntWrapper() {}

private:
	const int m_val;
};

void IntWrapper::print(std::ostream & os)
{
	os << m_val << " ";
}