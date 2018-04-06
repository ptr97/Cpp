#pragma once
#include "Urzadzenie.h"
#include "Rozdzielczosc.h"


//klasa dziedziczy po klasie Urzadzenie zeby dynamic_cast w lini 22 zwrocilo NULL'a 
class Skaner : virtual public Urzadzenie
{
public:
	Skaner(const Rozdzielczosc & roz) : Urzadzenie(), m_roz(roz) {}
	const Rozdzielczosc & rozdzielczosc() const {return m_roz;}

private:
	Rozdzielczosc m_roz;
};
