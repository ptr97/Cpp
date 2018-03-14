#pragma once

#include <string>
#include <iostream>
#include "Nazwany.h"
#include "Pojazd.h"
#include "Spalinowy.h"


class Samochod : public Pojazd, public Spalinowy
{
public:
	Samochod(std::string nazwa, const int vmax, const float oil) : Nazwany(nazwa), Pojazd(nazwa, vmax), Spalinowy(nazwa, oil) {}
	virtual void Wypisz() const 
	{
		std::cout << "To jest moje " << m_nazwa << std::endl;
		WypiszPredkoscMaksymalna();
		WypiszPoziomOleju();
	}

};

