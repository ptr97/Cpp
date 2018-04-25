#pragma once
#include <iostream>
#include <string>


class MyClass
{
public:
	MyClass(const char * name);
	MyClass(const MyClass & myClass);
	~MyClass();

	void SetName(const char * newName); 

private:
	std::string m_name;
};
