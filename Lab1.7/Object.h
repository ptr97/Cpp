#pragma once
#include <string>

struct tool;

namespace oop
{
class Object
{
public:
	virtual std::string name() const {return tool::rtti_real_name("Object");};
	virtual Object * get() {};
	virtual ~Object() {};
};
};
