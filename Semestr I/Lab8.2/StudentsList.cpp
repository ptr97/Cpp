#include "StudentsList.h"
#include <iostream>
#include <cstring>


StudentsList::StudentsList(const char * listName)
{
	int charCounter = 0;
	while( listName[charCounter] != '\0' )
		++charCounter;

	_listName = new char [charCounter + 1];
	strcpy(_listName, listName);

	_stu = NULL;
	_first = NULL;
}

void StudentsList::PrintInfo() const
{
	std::cout << "Students list: " << _listName << " (address: "  << this << ")" << std::endl;
}

void StudentsList::AddStudent(Student * stu)
{
	if(_stu == NULL)
	{
		_stu = stu;
		_first = stu;
	}
	else
	{
		while(_stu->Next() != NULL)
		{
			_stu = _stu->Next();
		}

		_stu->Next() = stu;
	}
	
	stu->ParentListRef() = this;
}

void StudentsList::AddStudent(const char * name, const char * surname)
{
	Student * stu = new Student(name, surname);
	AddStudent(stu);
}

void StudentsList::PrintAll()
{
	std::cout << _listName << std::endl;

	_stu = _first;

	while(_stu != NULL)
	{
		_stu->Print();
		_stu = _stu->Next();
	}
}

StudentsList::~StudentsList()
{
	delete [] _listName;

	_stu = _first;
	Student * stuCopy;

	while(_stu != NULL)
	{
		stuCopy = _stu->Next();
		delete _stu;
		_stu = stuCopy;
	}
}
