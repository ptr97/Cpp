#pragma once 
#include "Student.h"

class Student;

class StudentsList
{
public:
	StudentsList(const char * listName);
	void PrintInfo() const;
	void AddStudent(Student * stu);
	void AddStudent(const char * name, const char * surname);
	void PrintAll();
	~StudentsList();

private:
	char * _listName;
	Student * _stu;
	Student * _first;
};