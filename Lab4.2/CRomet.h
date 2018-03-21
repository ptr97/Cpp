#pragma once
#include "CMotorower.h"

class CRomet : public CMotorower
{
public:
	CRomet(const CSilnik silnik, const int przebieg) : CMotorower(silnik, "czerwony metalic", przebieg) {}
	void Print(std::ostream & os) const;
	friend std::ostream & operator<<(std::ostream & os, const CRomet & romet);

};

std::ostream & operator<<(std::ostream & os, const CRomet & romet)
{
	romet.CMotorower::Print(os);
	return os;
}
