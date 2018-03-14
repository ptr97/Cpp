#pragma once
#include "Object.h"
#include "SequenceContainer.h"

struct tool;

namespace oop
{
class List : public Object, public SequenceContainer
{
public:
	virtual std::string name() const {return tool::rtti_real_name("List");};

	
};
}
