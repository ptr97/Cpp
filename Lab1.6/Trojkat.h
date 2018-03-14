#pragma once
#include "Ksztalt.h"
#include <cmath>

//klasa Trojkata, dziedziczy publicznie po klasie Ksztalt, przechowuje dlugosci bokow trojkata
class Trojkat : public Ksztalt
{
public:
	//konstruktor, inicjalizuje dlugosci bokow trojkata
	Trojkat(const int a, const int b, const int c);
	
	//metoda wypisujaca dane trojkata do strumienia os 
	virtual void wypisz(std::ostream & os) const;

	//metoda obliczajaca pole trojkata
	virtual double polePow() const;

private:
	//tablica w ktorej przechowujemy dlugosci bokow trojkata
	int m_boki[3];
};
