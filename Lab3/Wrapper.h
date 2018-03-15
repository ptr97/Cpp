#pragma once
#include <iostream>

//klasa abstrakcyjna po ktorej interfejs dziedzicza klasy FloatWrapper, IntWrapper oraz StringWrapper
class Wrapper 
{
public:
	//metoda czysto wirtualna umozliwiajaca kopiowanie obiektow klas pochodnych
	virtual Wrapper * Copy() const = 0;
	
	//metoda czysto wirtualna ktora pozwala wypisywac do standardowego strumienia obiekt danej klasy
	virtual void print(std::ostream & os) const = 0;
	
	//destruktor wirtualny - poniewaz po tej klasie dziedzicza inne klasy
	virtual ~Wrapper() {}
};
