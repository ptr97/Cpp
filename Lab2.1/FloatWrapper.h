#pragma once
#include "Wrapper.h"

class FloatWrapper : public Wrapper
{
public:
	FloatWrapper(const float value) : m_val(value) {}
	virtual void print(std::ostream & os);
	virtual ~FloatWrapper() {}

private:
	const float m_val;
};

void FloatWrapper::print(std::ostream & os)
{
	os << m_val << " ";
}