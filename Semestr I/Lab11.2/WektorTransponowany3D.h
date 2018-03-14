#pragma once

#include "Wektor3D.h"

class Wektor3D;
class Macierz;


class WektorTransponowany3D
{
public:
	WektorTransponowany3D(const double x = 0, const double y = 0, const double z = 0) : m_x(x), m_y(y), m_z(z) {} ;
	void Wypisz() const;
	friend WektorTransponowany3D operator+(const WektorTransponowany3D & wekt1, const WektorTransponowany3D & wekt2);
	friend Wektor3D operator/(const Wektor3D & wektor, const WektorTransponowany3D & wektTrans);
	friend Macierz Wektor3D::operator*(const WektorTransponowany3D & wektTrans) const;
	friend Wektor3D & Wektor3D::operator<<(const WektorTransponowany3D & wektTrans);


private:
	double m_x;
	double m_y;
	double m_z;


};
