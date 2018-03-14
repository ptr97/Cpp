#pragma once

#include <string>
#include <iostream>
#include "Nazwany.h"
#include "Narzedzie.h"
#include "Reczny.h"

class Srubokret : public Narzedzie, public Reczny
{
public:
	Srubokret(std::string nazwa, std::string zastosowanie, std::string zrNapedu) : Nazwany(nazwa), Narzedzie(nazwa, zastosowanie), Reczny(nazwa, zrNapedu) {}
	virtual void Wypisz() const 
	{
		std::cout << "Srubokret typu " << m_nazwa << std::endl;
		WypiszZastosowanie();
		WypiszZrodloNapedu();
	}

};

