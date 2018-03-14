#include "Factory.h"
#include "TestObj.h"

#include <iostream>

using namespace std;


TestObj * Factory::m_statObj = NULL;
TestObj ** Factory::m_array = NULL;
int Factory::m_size = 0;

TestObj * Factory::produce()
{
	if(!m_array)
	{
		++m_size;
		m_array = new TestObj * [m_size];
		m_array[m_size - 1] = new TestObj();
	}
	else
	{
		++m_size;
		
		TestObj ** oldArray = m_array;
		m_array = new TestObj * [m_size];

		for(int i = 0; i < m_size - 1; ++i)
		{
			m_array[i] = oldArray[i];
		}
		delete [] oldArray;


		if(!m_statObj)
		{
			m_array[m_size - 1] = new TestObj();
		}
		else
		{
			m_array[m_size - 1] = new TestObj(*m_statObj);
		}
	}

	return m_array[m_size - 1];
}

void Factory::prototype(const TestObj& obj)
{
	m_statObj = new TestObj(obj);
}

void Factory::erase()
{
	for(int i = 0; i < m_size; ++i)
		delete m_array[i];

	delete [] m_array;

	if(m_statObj)
		delete m_statObj;
}
