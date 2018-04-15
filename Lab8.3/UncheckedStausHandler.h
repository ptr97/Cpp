#pragma once
#include "UncheckedStausCode.h"


class UncheckedStausHandler
{
public:
	static void handle();
};

void UncheckedStausHandler::handle()
{
	try
	{
		throw;
	}
	catch(const UncheckedStausCode & exc)
	{
		std::cout << "..Handling " << "UncheckedStatusCode " << exc.what() << std::endl;
	}
	catch(const std::exception & exc)
	{
		std::cout << "..Handling " << "std::exception " << exc.what() << std::endl;
	}
}