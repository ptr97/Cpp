#pragma once
#include "Obserwator.h"

class ObserwatorLicznik : public ObserwatorBaza
{
public:
	ObserwatorLicznik() : m_suma(0) {}
	virtual void PrzetwarzajDane(const int dane) {m_suma += dane;}
	int suma() const {return m_suma;}

private:
	int m_suma;
};
