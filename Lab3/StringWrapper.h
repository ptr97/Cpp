#pragma once
#include <string>
#include "Wrapper.h"

//klasa StringWrapper - przechowujaca string
class StringWrapper : public Wrapper 
{
public:
	////konstruktor klasy StringWrapper - inicjalizuje wartosc StringWrapper'a przekazana wartoscia 
	StringWrapper(const std::string name) : m_value(name) {}
	
	//metoda wirtualna ktora zwraca kopie obiektu na rzecz ktorego jest wywolana
	virtual StringWrapper * Copy() const;
	
	//metoda wirtualna pozwalajaca wydrukowac obiekt tej klasy do standardowego strumienia
	virtual void print(std::ostream & os) const;

private:
	//wartosc przechowywana w klasie
	const std::string m_value;
};

