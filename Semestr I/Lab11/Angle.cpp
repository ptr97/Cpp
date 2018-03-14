#include "Angle.h"

#include <cmath>

Angle::Angle(const double radian)
{
	double radProper = radian;
	
	while(radProper >= (2 * M_PI))
		radProper -= 2 * M_PI;

	while(radProper < 0)
		radProper += 2 * M_PI;

	m_degrees = radProper * 180 / M_PI;
}

Angle::Angle(const Angle& angle)
{
	m_degrees = angle.deg();
}

double Angle::rad() const
{
	return m_degrees * M_PI / 180;
}

double Angle::deg() const
{
	return m_degrees;
}

double & Angle::deg()
{
	return m_degrees;
}

Angle Angle::distance(const Angle & val1, const Angle & val2)
{
	double radDiff = val1.rad() - val2.rad();

	while(radDiff >= (2 * M_PI))
		radDiff -= 2 * M_PI;

	while(radDiff < 0)
		radDiff += 2 * M_PI;

	if(radDiff >= M_PI)
		radDiff = (2 * M_PI) - radDiff;

	Angle dif = Angle(radDiff);

	return dif;
}

Angle::operator int() const
{
	return int(m_degrees);
}
