#include "Grade.h"

#include <iostream>

int Grade::nextID = 1;

Grade::Grade(const double value) : m_ID(nextID), m_grade(value)
{
	++nextID;
}

void Grade::print() const
{
	std::cout << "Grade ID=" << m_ID << " value=" << m_grade << std::endl;
}


