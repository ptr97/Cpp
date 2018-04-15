#include "Object.h"


Object::Object(std::string name) : m_name(name)
{
	std::cout << "Construct: " << m_name << std::endl;
}

Object::~Object()
{
	std::cout << "Destruct: " << m_name << std::endl;
}

void Object::Skip() const
{
	throw 0;
}
