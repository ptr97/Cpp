#pragma once

//dolaczone pliki naglowkowe 
#include "TwoArg.h"
#include "OneArg.h"
#include "OR.h"
#include "AND.h"
#include "NOT.h"

//klasa Logical ktora ma za zadanie symulowac wyniki operacji logicznych, ma tylko metody statyczne
class Logical
{
public:
	//metoda statyczna inline ktora zwraca wynik operacji logicznej dwuargumetowej 
	static bool eval(const TwoArg & op, const bool arg1, const bool arg2)
	{
		return op.result(arg1, arg2);
	}

	//metoda statyczna inline ktora zwraca wynik operacji logicznej jednoargumetowej 
	static bool eval(const OneArg & op, const bool arg)
	{
		return op.result(arg);
	}
};
