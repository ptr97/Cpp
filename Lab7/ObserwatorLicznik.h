#pragma once

#include "ObserwatorBaza.h"

//klasa ktora dziedziczy po Obserwatorze, jej funkcjonalnoscia jest liczenie sumy otrzymanych danych
class ObserwatorLicznik : public Obserwator
{
public:
	//metoda przetwarzjaca dane - dodajaca do sumy wszystkich przetworzonych elementow
	virtual void przetworzDane(const int dane) {m_suma += dane;}
	
	//getter do skladnika prywatnego m_suma
	int suma() const {return m_suma;}

private:
	//skladnik przechowujacy sume przetworzonych elementow - przy inicjalizacji ustawiany jest na 0 - std=c++11
	int m_suma = 0;
}; 