#include "IntWrapper.h"

void IntWrapper::print(std::ostream & os) const
{
	os << m_value << " ";
}

IntWrapper * IntWrapper::Copy() const
{
	IntWrapper * newPtr = new IntWrapper(m_value);

	return newPtr;
}