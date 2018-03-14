#pragma once

#include <string>
#include <iostream>
#include "Nazwany.h"
#include "Pojazd.h"
#include "Reczny.h"

class Rower : public Pojazd, public Reczny
{
public:
	Rower(std::string nazwa, const int vmax, std::string zrNapedu) : Nazwany(nazwa), Pojazd(nazwa, vmax), Reczny(nazwa, zrNapedu) {}
	virtual void Wypisz() const 
	{
		std::cout << "Wypisuje rower " << m_nazwa << std::endl;
		WypiszPredkoscMaksymalna();
		WypiszZrodloNapedu();
	}

};

