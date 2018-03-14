#include "Grade.h"
#include "Student.h"

#include <iostream>

Grade::Grade(const int grade, Student& student)
{
	m_value = grade;

	int * oldArray = student.m_grades;

	student.m_gradesCounter += 1;

	const int size = student.m_gradesCounter;

	student.m_grades = new int [size];
	
	for(int i = 0; i < size - 1; ++i)
	{
		(student.m_grades)[i] = oldArray[i];
	}

	delete [] oldArray;

	(student.m_grades)[size - 1] = grade;

	m_whose = & student.m_ID;
}

void Grade::print() const
{
	std::cout << "Grade print value=" << m_value << " studentID=" << *m_whose << std::endl;
}

