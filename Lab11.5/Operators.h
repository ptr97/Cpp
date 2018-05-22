#pragma once

#include <iostream>
#include "UniquePointer.h"


template <typename T>
std::ostream & operator<<(std::ostream & os, const UniquePointer<T> & unqPtr)
{
	os << "[pointing to " << &*unqPtr << "]";

	return os;
}
