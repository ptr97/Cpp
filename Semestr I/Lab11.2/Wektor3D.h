#pragma once

#include <iostream>

class WektorTransponowany3D;
class Macierz;

class Wektor3D
{
public:
	Wektor3D(const double x = 0, const double y = 0, const double z = 0) : m_x(x), m_y(y), m_z(z) {} ;
	void Wypisz() const;
	Wektor3D operator+(const Wektor3D & wektor) const;
	friend Wektor3D operator/(const Wektor3D & wektor, const WektorTransponowany3D & wektTrans);
	Macierz operator*(const WektorTransponowany3D & wektTrans) const;
	Wektor3D & operator<<(const WektorTransponowany3D & wektTrans);
	friend std::ostream & operator<<(std::ostream & os, const Wektor3D & wekt);
	void * operator new(size_t size);
	void operator delete(void * ptr);
	Wektor3D & operator++();
	Wektor3D operator++(int);

private:
	double m_x;
	double m_y;
	double m_z;

	static int m_howMany;
};

