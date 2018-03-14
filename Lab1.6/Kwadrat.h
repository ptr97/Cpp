#pragma once
#include "Ksztalt.h"

//Klasa Kwadrat ktora dziedziczy publicznie po klasie Ksztalt, przechowuje dlugosc boku kwadratu
class Kwadrat : public Ksztalt
{
public:
	//konstruktor klasy Kwadrat - inicjalizuje dlugosc boku obiektu
	Kwadrat(const int bok);

	//metoda wypisujaca dane kwadratu do strumienia os 
	virtual void wypisz(std::ostream & os) const;

	//metoda obliczajaca pole kwadratu
	virtual double polePow() const;

private:
	//dlugosc boku trojkata
	const int m_bok;
};
