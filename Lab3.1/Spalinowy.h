#pragma once

#include <string>
#include <iostream>
#include "Nazwany.h"


class Spalinowy : virtual public Nazwany
{
public:
	Spalinowy(std::string nazwa, const float oil) : Nazwany(nazwa), m_oil(oil) {}
	
	void WypiszPoziomOleju() const 
	{
		std::cout << "Poziom oleju wynosi " << m_oil << "." << std::endl;
	}

private:
	const float m_oil;
};

