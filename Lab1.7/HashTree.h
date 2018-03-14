#pragma once
#include "Object.h"
#include "Container.h"

struct tool;

namespace oop
{
class HashTree : public Object, public Container
{
public:
	virtual std::string name() const {return tool::rtti_real_name("HashTree");};
	
};
}
