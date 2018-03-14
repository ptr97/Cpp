#pragma once
#include "Stan.h"
#include <iostream>

class MaszynaStanow
{
public:
	MaszynaStanow();
	void start();
	void operator+=(Stan * stan);
	MaszynaStanow & operator()();
	void operator++();
	void operator--();
	~MaszynaStanow();
	friend std::ostream & operator<<(std::ostream & os, const MaszynaStanow & ms);

private:
	Stan ** m_tab;
	int m_stan;
	int m_licznik;

};
