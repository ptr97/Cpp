#include "FloatWrapper.h"

void FloatWrapper::print(std::ostream & os) const
{
	os << m_value << " ";
}

FloatWrapper * FloatWrapper::Copy() const
{
	FloatWrapper * newPtr = new FloatWrapper(m_value);

	return newPtr;
}