#include "MyClass.h"


MyClass::MyClass(const char * name) : m_name(name)
{
	std::cout << "Created MyClass:" << m_name << std::endl;
}

MyClass::MyClass(const MyClass & myClass)
{
	m_name = myClass.m_name;
	std::cout << "Copy created MyClass:" << m_name << std::endl;
}

MyClass::~MyClass()
{
	std::cout << "Destroyed MyClass:" << m_name << std::endl;
}

void MyClass::SetName(const char * newName)
{
	m_name = newName;
}
