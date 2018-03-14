#pragma once
#include "HashTree.h"
#include "Container.h"

struct tool;

namespace oop
{
class HashMultiTree : public Object, public Container
{
public:
	virtual std::string name() const {return tool::rtti_real_name("HashMultiTree");};
	
};
}
