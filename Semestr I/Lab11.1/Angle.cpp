#include "Angle.h"

#include <cmath>


Angle::Angle(const double value) : m_radians(value)
{
	
}

Angle Angle::fromRadians(const double radians)
{
	double properRadians = radians;

	while(properRadians < 0)
		properRadians += 2 * M_PI;

	while(properRadians >= 2 * M_PI)
		properRadians -= 2* M_PI;

	return Angle(properRadians);
}

Angle Angle::fromDegrees(const double degrees)
{
	double properRadians = degrees * M_PI / 180;

	while(properRadians < 0)
		properRadians += 2 * M_PI;

	while(properRadians >= 2 * M_PI)
		properRadians -= 2* M_PI;

	return Angle(properRadians);
}

Angle Angle::distance(const Angle& ang1, const Angle& ang2)
{
	double properRadians = ang1.m_radians - ang2.m_radians;

	while(properRadians < 0)
		properRadians += 2 * M_PI;

	while(properRadians >= 2 * M_PI)
		properRadians -= 2* M_PI;

	if(properRadians > M_PI)
		properRadians = 2 * M_PI - properRadians;

	return Angle(properRadians);
}

double Angle::toRad() const
{
	return m_radians;
}

double Angle::toDeg() const
{
	return (m_radians * 180 / M_PI);
}

Angle::Angle(const Angle& angle) : m_radians(angle.m_radians)
{

}

Angle& Angle::add(const Angle& angle)
{
	m_radians += angle.m_radians;

	while(m_radians < 0)
		m_radians += 2 * M_PI;

	while(m_radians >= 2 * M_PI)
		m_radians -= 2* M_PI;

	return *this; 
}

Angle::operator int() const
{
	return int(m_radians);
}

