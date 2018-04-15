#pragma once
#include <string>
#include <iostream>


class Object
{
public:
	Object(std::string name);
	~Object();
	void Skip() const;

private:
	std::string m_name;
};
