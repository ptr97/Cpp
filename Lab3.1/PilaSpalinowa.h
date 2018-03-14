#pragma once

#include <string>
#include <iostream>
#include "Nazwany.h"
#include "Narzedzie.h"
#include "Spalinowy.h"

class PilaSpalinowa : public Narzedzie, public Spalinowy
{
public:
	PilaSpalinowa(std::string nazwa, std::string zastosowanie, const float oil) : Nazwany(nazwa), Narzedzie(nazwa, zastosowanie), Spalinowy(nazwa, oil) {}
	virtual void Wypisz() const 
	{
		std::cout << "Pila spalinowa marki " << m_nazwa << std::endl;
		WypiszZastosowanie();
		WypiszPoziomOleju();
	}

};

