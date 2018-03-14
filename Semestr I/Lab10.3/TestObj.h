#pragma once

class TestObj
{
public:
	TestObj();

	TestObj(const char * name);

	TestObj(const TestObj & obj);

	const char * name() const 
	{return m_name;}; 

	~TestObj();

private:
	const char * m_name;
};
