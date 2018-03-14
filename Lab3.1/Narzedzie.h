#pragma once

#include <string>
#include <iostream>
#include "Nazwany.h"


class Narzedzie : virtual public Nazwany
{
public:
	Narzedzie(std::string nazwa, std::string zastosowanie) : Nazwany(nazwa), m_zastosowanie(zastosowanie) {}
	
	void WypiszZastosowanie() const 
	{
		std::cout << "Tego narzedzia uzywa sie do " << m_zastosowanie << "." << std::endl;
	}

private:
	const std::string m_zastosowanie;
};

