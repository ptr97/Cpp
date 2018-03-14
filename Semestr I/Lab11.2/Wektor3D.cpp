#include "Wektor3D.h"
#include "WektorTransponowany3D.h"
#include "Macierz.h"

int Wektor3D::m_howMany = 0;

void Wektor3D::Wypisz() const
{
	std::cout << "Wektor3D" << std::endl;
	std::cout << "(" << m_x << ", " << m_y << ", " << m_z << ")" << std::endl;
}

Wektor3D Wektor3D::operator+(const Wektor3D & wektor) const
{
	const double x = m_x + wektor.m_x;
	const double y = m_y + wektor.m_y;
	const double z = m_z + wektor.m_z;

	return Wektor3D(x, y, z);
}

Wektor3D operator/(const Wektor3D & wektor, const WektorTransponowany3D & wektTrans)
{
	const double x = wektor.m_x / wektTrans.m_x;
	const double y = wektor.m_y / wektTrans.m_y;
	const double z = wektor.m_z / wektTrans.m_z;

	return Wektor3D(x, y, z);
}

Macierz Wektor3D::operator*(const WektorTransponowany3D & wektTrans) const
{
	double tab[3][3];
	const double tabWektor[3] = {m_x, m_y, m_z};
	const double tabWektorTrans[3] = {wektTrans.m_x, wektTrans.m_y, wektTrans.m_z};

	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			tab[i][j] = tabWektor[i] * tabWektorTrans[j];
		}
	}

	return Macierz(tab, 3);
}

Wektor3D & Wektor3D::operator<<(const WektorTransponowany3D & wektTrans)
{
	m_x = wektTrans.m_x;
	m_y = wektTrans.m_y;
	m_z = wektTrans.m_z;

	return *this;
}

std::ostream & operator<<(std::ostream & os, const Wektor3D & wekt)
{
	os << "(" << wekt.m_x << ", " << wekt.m_y << ", " << wekt.m_z << ")" << std::endl;

	return os;
}

void * Wektor3D::operator new(size_t size)
{
	void * pointer = ::new Wektor3D();
	++m_howMany;
	std::cout << "Zaalokowano obiekt o rozmiarze : " << size << std::endl;
	std::cout << "Ilosc obiektow zaalokowanych dynamicznie: " << m_howMany << std::endl;

	return pointer;
}

void Wektor3D::operator delete(void * ptr)
{
	--m_howMany;
	std::cout << "Ilosc obiektow zaalokowanych dynamicznie: " << m_howMany << std::endl;

	::delete ptr;
}

Wektor3D & Wektor3D::operator++()
{
	m_x += 2;
	m_y += 2;
	m_z += 2;

	return *this;
}

Wektor3D Wektor3D::operator++(int)
{
	Wektor3D temp = *this;

	m_x += 1;
	m_y += 1;
	m_z += 1;

	return temp;
}
