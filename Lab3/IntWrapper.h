#pragma once
#include "Wrapper.h"

//klasa IntWrapper przechowujaca integer'a
class IntWrapper : public Wrapper 
{
public:
	//konstruktor klasy IntWrapper - inicjalizuje wartosc IntWrapper'a przekazana wartoscia 
	IntWrapper(const int value) : m_value(value) {}

	//metoda wirtualna ktora zwraca kopie obiektu na rzecz ktorego jest wywolana
	virtual IntWrapper * Copy() const;

	//metoda wirtualna pozwalajaca wydrukowac obiekt tej klasy do standardowego strumienia
	virtual void print(std::ostream & os) const;

private:
	//wartosc przechowywana w klasie
	const int m_value;
};

