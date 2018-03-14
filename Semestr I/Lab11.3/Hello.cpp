#include "Hello.h"

#include <iostream>

Hello::Hello()
{
	std::cout << "false start" << std::endl;
}

Hello::~Hello()
{
	std::cout << "bye bye" << std::endl;
}
