#pragma once
#include "Ksztalt.h"
#include <cmath>

//klasa Kolo, dziedziczy publicznie po klasie Ksztalt, przechowuje promien kola
class Kolo : public Ksztalt
{
public:
	//konstruktor, inicjalizuje promien kola
	Kolo(const int promien);

	//metoda wypisujaca dane kola do strumienia os 
	virtual void wypisz(std::ostream & os) const;

	//metoda obliczajaca pole kola
	virtual double polePow() const;

private:
	//dlugosc promienia kola
	const int m_promien;
};
