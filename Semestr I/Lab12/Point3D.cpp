#include "Point3D.h"


Point3D::Point3D(const double x, const double y, const double z)
{
	m_coordinate[0] = x;
	m_coordinate[1] = y;
	m_coordinate[2] = z;
}

std::ostream & operator<<(std::ostream & os, const Point3D & point)
{
	os << "(";

	for(int i = 0; i < 3; ++i)
	{
		os << point.m_coordinate[i];

		if(i % 3 != 2)
			os << ", ";
	}

	os << ")";

	return os;
}

double & Point3D::operator[](const int number)
{
	return m_coordinate[number];
}

double Point3D::operator[](const int number) const
{
	return m_coordinate[number];
}
