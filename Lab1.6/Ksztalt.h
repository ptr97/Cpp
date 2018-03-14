#pragma once
#include <iostream>

//klasa czysto wirtualna Ksztalt - udostepnia interfejs do dziedziczenia dla klas pochodnych
class Ksztalt
{
public:
	//metoda virtualna wypisujaca do podandego strumienia wyjsciowego os parametry danego ksztaltu
	virtual void wypisz(std::ostream & os) const = 0;

	//metoda wyliczajaca pole powierzchni dla danego ksztaltu
	virtual double polePow() const {return 0;};

	//destruktor wirtualny - do dziedziczenia
	virtual ~Ksztalt() {};

};

//funkcja globalna wypisujaca wartosci danego obiektu
void wypisz(const Ksztalt & ksz);
