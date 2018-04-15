#pragma once
#include <stdexcept>
#include <string>


class UncheckedStausCode : public std::runtime_error
{
public:
	UncheckedStausCode(std::string errorName) : std::runtime_error(errorName) {}
};
