#include "GradeBook.h"
#include "Grade.h"

#include <iostream>


GradeBook::GradeBook() : m_size(0)
{
	m_array = NULL;
}

void GradeBook::insert(const Grade * grade)
{
	Grade ** oldArray = m_array;
	++m_size;

	m_array = new Grade * [m_size];
	for(int i = 0; i < m_size - 1; ++i)
		m_array[i] = oldArray[i];
	
	delete [] oldArray;

	Grade * newGrade = new Grade(*grade);
	delete grade;

	m_array[m_size - 1] = newGrade;
}

void GradeBook::print() const
{
	std::cout << "Grades in the book:" << std::endl;
	for(int i = 0; i < m_size; i++)
		(m_array[i])->Grade::print();
	std::cout << std::endl;
}

void GradeBook::addGrade(const int value)
{
	const Grade * newGrade = new Grade(value);
	return this->insert(newGrade);
}

GradeBook::~GradeBook()
{
	for(int i = 0; i < m_size; ++i)
		delete m_array[i];

	delete [] m_array;
}

