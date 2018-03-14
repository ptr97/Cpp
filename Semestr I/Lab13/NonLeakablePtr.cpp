#include "NonLeakablePtr.h"
#include "NonLeakable.h"
#include <iostream>

NonLeakablePtr::NonLeakablePtr()
{
	m_object = NULL;
}

 NonLeakablePtr::~NonLeakablePtr() {
 	if (m_object) {
 		std::cout << "Destroying object " << m_object->myID() << std::endl;
 		delete m_object;
 		m_object = NULL;
 	}
 }


void NonLeakablePtr::MakeNewObject() {
	if (m_object != NULL) {
		delete m_object;
		m_object = NULL;
	}
	m_object = ::new NonLeakable();
}

NonLeakablePtr::NonLeakablePtr(NonLeakablePtr& ptr)
{
	m_object = ptr.m_object;
	ptr.m_object = NULL;
}


void NonLeakablePtr::Print() const {
	std::cout << "Object pointing to ";
	if (!m_object)
		std::cout << "nothing";
	else 
		std::cout << m_object;
	std::cout << std::endl;
}

NonLeakable* NonLeakablePtr::operator->() const {
	return m_object;
}

NonLeakablePtr& NonLeakablePtr::operator=(NonLeakablePtr& ptr) {
	if (this == &ptr)
		return *this;
	m_object = ptr.m_object;
	ptr.m_object = NULL;
	return *this;
}

NonLeakable& NonLeakablePtr::operator*(){
	return *m_object;
}
