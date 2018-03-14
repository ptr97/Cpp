#include "Student.h"
#include <iostream>
#include <cstring>

int Student::nextID = 1;


Student::Student(const char * name, const char * surname)
{
	_id = nextID;
	++nextID;

	int charCounter = 0;
	while(name[charCounter] != '\0')
		++charCounter;

	_name = new char [charCounter + 1];
	strcpy(_name, name);

	charCounter = 0;
	while(surname[charCounter] != '\0')
		++charCounter;

	_surname = new char [charCounter + 1];
	strcpy(_surname, surname);

	_next = NULL;
	_parentList = NULL;
}

void Student::Print() const
{
	std::cout << "Student " << _id << ": " << _name << ", " << _surname << std::endl;
}

StudentsList* Student::ParentList() const
{
	return _parentList;
}

Student*& Student::Next()
{
	return _next;
}

StudentsList*& Student::ParentListRef()
{
	return _parentList;
}

char*& Student::Name()
{
	return _name;
}

char*& Student::Surname()
{
	return _surname;
}

Student::~Student()
{
	delete [] Name();
	delete [] Surname();
}