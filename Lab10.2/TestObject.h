#pragma once
#include <iostream>


class TestObject
{
public:
	TestObject(const int id = 1) : m_id(id) {}
	void Print() const {std::cout << "Object with ID=" << m_id << std::endl;}
	void Set(const int newID) {m_id = newID;}

private:
	int m_id;
};
