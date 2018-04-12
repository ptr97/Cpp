#pragma once

#include "ObserwatorBaza.h"
#include <iostream>

//klasa ktora dziedziczy po Obserwatorze, jej funkcjonalnoscia jest wypisywanie otrzymanych do przetworzenia danych na ekran
class ObserwatorWypisywacz : public Obserwator
{
public:
	//metoda przetwarzjaca dane - wypisujaca na ekran
	virtual void przetworzDane(const int dane) {std::cout << " " << dane;}
};