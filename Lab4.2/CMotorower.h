#pragma once
#include <string>
#include <iostream>
#include "CSilnik.h"


class CMotorower
{
public:
	CMotorower(const CSilnik silnik, const char * kolor, const int przebieg) : m_liczbaKol(2), m_silnik(silnik), m_kolor(kolor), m_przebieg(przebieg) {}
	void Print(std::ostream & os) const;
	friend std::ostream & operator<<(std::ostream & os, const CMotorower & motorower);

private:
	const int m_liczbaKol;
	const CSilnik m_silnik;
	const std::string m_kolor;
	const int m_przebieg;
};

void CMotorower::Print(std::ostream & os) const
{
	os << std::endl;
	os << "Liczba kol " << m_liczbaKol << std::endl;
	os << "Stan licznika " << m_przebieg << " [km]" << std::endl;
	os << "Kolor " << m_kolor << std::endl;
}

std::ostream & operator<<(std::ostream & os, const CMotorower & motorower)
{
	motorower.Print(os);
	return os;
}
