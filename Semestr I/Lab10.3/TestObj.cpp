#include "TestObj.h"

#include <iostream>

using namespace std;

TestObj::TestObj() : m_name("default")
{
	cout << "TestObj::TestObj()" << endl;
}

TestObj::TestObj(const char * name) : m_name(name)
{
	cout << "TestObj::TestObj(\"" << m_name << "\")" << endl;
}

TestObj::TestObj(const TestObj & obj) : m_name(obj.m_name)
{
	cout << "TestObj::TestObj(TestObj(\"" << m_name << "\"))" << endl;
}

TestObj::~TestObj()
{
	cout << "~TestObj(): " << m_name << endl;
}
