#include "StringWrapper.h"

void StringWrapper::print(std::ostream & os) const
{
	os << m_value << " ";
}

StringWrapper * StringWrapper::Copy() const
{
	StringWrapper * newPtr = new StringWrapper(m_value);

	return newPtr;
}