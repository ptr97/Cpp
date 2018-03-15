#pragma once
#include "Wrapper.h"

//klasa FloatWrapper przechowujaca Float'a
class FloatWrapper : public Wrapper 
{
public:
	//konstruktor klasy FloatWrapper - inicjalizuje wartosc FloatWrapper'a przekazana wartoscia 
	FloatWrapper(const float value) : m_value(value) {}
	
	//metoda wirtualna ktora zwraca kopie obiektu na rzecz ktorego jest wywolana
	virtual FloatWrapper * Copy() const;
	
	//metoda wirtualna pozwalajaca wydrukowac obiekt tej klasy do standardowego strumienia
	virtual void print(std::ostream & os) const;

private:
	//wartosc przechowywana w klasie
	const float m_value;
};

