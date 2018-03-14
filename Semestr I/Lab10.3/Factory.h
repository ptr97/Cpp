#pragma once

class TestObj;

class Factory
{
public:
	static TestObj * produce();
	static void prototype(const TestObj& obj);
	static void erase();

private:
	static TestObj * m_statObj;
	static TestObj ** m_array;
	static int m_size;
};
