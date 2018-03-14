#pragma once
#include <string>
#include "SequenceContainer.h"

struct tool;

namespace oop
{
class Container
{
public:
	virtual std::string name() const { return tool::rtti_real_name("Container");};
	virtual int size() const {};
	virtual bool empty() const {};
	virtual Object * get() {}; 
	virtual bool insert(SequenceContainer * sc) {};
	virtual ~Container() {};
};

}
