#include "Student.h"
#include "Grade.h"

#include <iostream>


Student::Student()
{
	m_ID = 0;
	m_grades = NULL;
	m_gradesCounter = 0;
}

void Student::setID(const int & ID)
{
	m_ID = ID;
}

void Student::print() const
{
	std::cout << "Student print ID=" << m_ID;
	if(m_grades)
	{
		std::cout << " grades: ";

		for(int i = 0; i < m_gradesCounter; ++i)
		{
			std::cout << m_grades[i] << " ";
		}
	}
	std::cout << std::endl;
}

// int *& Student::Grades()
// {
// 	return m_grades;
// }

// int * Student::ID()
// {
// 	return & m_ID;
// }

// int & Student::GradesCounter()
// {
// 	return m_gradesCounter;
// }

Student::~Student()
{
	if(m_grades)
		delete [] m_grades;
}