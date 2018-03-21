#pragma once
#include <string>
#include <iostream>
#include "CSilnik.h"


class CSamochod
{
public:
	CSamochod(const CSilnik silnik, const char * kolor, const int przebieg) : m_liczbaKol(4), m_silnik(silnik), m_kolor(kolor), m_przebieg(przebieg) {}
	CSamochod(const CSamochod & s) : m_liczbaKol(4), m_silnik(s.m_silnik), m_kolor(s.m_kolor), m_przebieg(0) {}
	void Print(std::ostream & os) const;
	friend std::ostream & operator<<(std::ostream & os, const CSamochod & samochod);

private:
	const int m_liczbaKol;
	const CSilnik m_silnik;
	const std::string m_kolor;
	const int m_przebieg;
};

void CSamochod::Print(std::ostream & os) const
{
	os << std::endl;
	os << "Liczba kol " << m_liczbaKol << std::endl;
	os << "Stan licznika " << m_przebieg << " [km]" << std::endl;
	os << "Kolor " << m_kolor << std::endl;

}

std::ostream & operator<<(std::ostream & os, const CSamochod & samochod)
{
	samochod.Print(os);
	return os;
}
