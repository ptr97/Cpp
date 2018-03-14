#include "NonLeakable.h"
#include <iostream>

int NonLeakable::m_id = 0;

NonLeakable::NonLeakable() {
	m_myid = m_id;
	std::cout << "Constructing object " << m_myid << std::endl;
	++m_id;
}

NonLeakable::~NonLeakable() {
	std::cout << "Destroying object " << m_myid << std::endl;
}

void * NonLeakable::operator new(long unsigned int) {
	return ::new NonLeakable();
}

void NonLeakable::Print() const {
	std::cout << "This is object with ID=" << m_myid << std::endl;
}

int NonLeakable::myID() const {
	return m_myid;
}