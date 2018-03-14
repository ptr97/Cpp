#include "Grade.h"
#include "Student.h"

#include <iostream>

Grade::Grade(const int grade, Student& student)
{
	m_value = grade;

	int * oldArray = student.Grades();

	student.GradesCounter() += 1;

	const int size = student.GradesCounter();

	student.Grades() = new int [size];
	
	for(int i = 0; i < size - 1; ++i)
	{
		(student.Grades())[i] = oldArray[i];
	}

	delete [] oldArray;

	(student.Grades())[size - 1] = grade;

	m_whose = student.ID();
}

void Grade::print() const
{
	std::cout << "Grade print value=" << m_value << " studentID=" << *m_whose << std::endl;
}

