#pragma once
#include "CSamochod.h"

class CMercedes : public CSamochod
{
public:
	CMercedes(const CSilnik silnik, const int przebieg) : CSamochod(silnik, "czarny metalic", przebieg) {}
	friend std::ostream & operator<<(std::ostream & os, const CMercedes & mercedes);

};

std::ostream & operator<<(std::ostream & os, const CMercedes & mercedes)
{
	mercedes.CSamochod::Print(os);
	return os;
}
