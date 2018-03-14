#pragma once
#include "OneArg.h"

//klasa pochodna po klasie OneArg ktora reprezentuje operacje logiczna NOT
class NOT : public OneArg
{
public:
	//metoda inline zwracajaca wynik operacji NOT
	virtual bool result(const bool arg) const
	{
		return !arg;
	}
};
