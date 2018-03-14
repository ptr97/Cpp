#pragma once
#include <string>
#include "Object.h"

struct tool;

namespace oop
{
class SequenceContainer
{
public:
	virtual std::string name() const { return tool::rtti_real_name("SequenceContainer");};
	virtual bool push_front(Object * o) {};
	virtual bool push_back(Object * o) {};
	virtual Object * get() {};
	virtual ~SequenceContainer(){};
};

}
