#pragma once

#include <string>
#include <iostream>
#include "Nazwany.h"


class Reczny : virtual public Nazwany
{
public:
	Reczny(std::string nazwa, std::string zrNapedu) : Nazwany(nazwa), m_zrNapedu(zrNapedu) {}
	
	void WypiszZrodloNapedu() const 
	{
		std::cout << "Do napedzenia tego urzadzenia uzywa sie " << m_zrNapedu << "." << std::endl;
	}

private:
	const std::string m_zrNapedu;
};

