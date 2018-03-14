#include "WektorTransponowany3D.h"


#include <iostream>


void WektorTransponowany3D::Wypisz() const
{
	std::cout << "WektorTransponowany3D" << std::endl;
	std::cout << "(" << m_x << ", " << m_y << ", " << m_z << ")" << std::endl;
}

WektorTransponowany3D operator+(const WektorTransponowany3D & wekt1, const WektorTransponowany3D & wekt2)
{
	const double x = wekt1.m_x + wekt2.m_x;
	const double y = wekt1.m_y + wekt2.m_y;
	const double z = wekt1.m_z + wekt2.m_z;

	return WektorTransponowany3D(x, y, z);
}
