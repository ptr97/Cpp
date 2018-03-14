#pragma once
#include "TwoArg.h"

//klasa pochodna po klasie TwoArg ktora reprezentuje operacje logiczna OR
class OR : public TwoArg
{
public:
	//metoda inline zwracajaca wynik operacji OR
	virtual bool result(const bool arg1, const bool arg2) const
	{
		return arg1 || arg2;
	}
};
