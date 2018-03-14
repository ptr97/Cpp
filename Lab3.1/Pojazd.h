#pragma once

#include <string>
#include <iostream>
#include "Nazwany.h"


class Pojazd : virtual public Nazwany
{
public:
	Pojazd(std::string nazwa, const int vmax) : Nazwany(nazwa), m_vmax(vmax) {}
	
	void WypiszPredkoscMaksymalna() const 
	{
		std::cout << "Predkosc maksymalna tego pojazdu wynosi " << m_vmax << "km/h." << std::endl;
	}

private:
	const int m_vmax;
};

