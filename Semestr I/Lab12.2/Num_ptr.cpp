#include "Num_ptr.h"
#include "Number.h"

#include <iostream>


Num_ptr::Num_ptr(Number * ptrNumber) : ref(m_toDelete), m_toDelete(true)
{
	m_ptrNumber = ptrNumber;
}

Number * Num_ptr::operator->()
{
	return m_ptrNumber;
}

Num_ptr & Num_ptr::operator=(Number * ptrNumber)
{
	if(m_ptrNumber)
		(*this).Delete();

	m_ptrNumber = ptrNumber;
	m_toDelete = true;

	return *this;
}

Num_ptr & Num_ptr::operator=(Num_ptr & num_ptr)
{
	if(&num_ptr == this)
		return *this;

	if(m_ptrNumber)
		(*this).Delete();

	m_ptrNumber = num_ptr.m_ptrNumber;
	m_toDelete = num_ptr.m_toDelete;

	num_ptr.m_ptrNumber = NULL;

	return *this;
}

void Num_ptr::Delete()
{
	if(m_ptrNumber && ref)
	{
		delete m_ptrNumber;
		ref = false;
	}
}

Num_ptr::~Num_ptr()
{
	if(ref && m_ptrNumber)
		(*this).Delete();
}

Num_ptr::Num_ptr(const Num_ptr & num_ptr) : ref(num_ptr.ref), m_toDelete(num_ptr.m_toDelete)
{
	m_ptrNumber = num_ptr.m_ptrNumber;
}