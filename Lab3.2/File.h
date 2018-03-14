#pragma once
#include "SystemObject.h"

class File : public SystemObject
{
public:
	File(const std::string name) : SystemObject(name) {}
	void print(std::ostream & os, const int spaces) const;
	~File() {}
};

void File::print(std::ostream & os, const int spaces) const
{
	for(int i = 0; i < spaces; ++i)
		os << " ";

	os << Name() << std::endl;
}

