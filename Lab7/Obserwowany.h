#pragma once

#include <vector>
#include "Obserwator.h"

//klasa bazowa Obserwowany, ktora reprezentuje obserwowany obiekt we wzorcu projektowym "Obserwator" 
//przechowuje ona obiekty, ktore ja obserwuja, umozliwia ich dodawanie oraz informuje je o otrzymaniu nowych danych
class Obserwowany
{
public:
	//metoda informujaca wszystkich obserwatorow o nowych danych do ich przetworzenia
	void noweDaneNadeszly(const int dane);

	//metoda dodajaca kolejnego obserwatora
	void dodajObserwatora(Obserwator * obserwator);
	
	//wirtualny destruktor, poniewaz po tej klasie dziedziacza inne
	virtual ~Obserwowany() {}

private:
	std::vector<Obserwator *> m_obserwatorzy;
};
