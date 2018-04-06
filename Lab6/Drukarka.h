#pragma once
#include "Papierozerne.h"
#include "Rozdzielczosc.h"


//klasa Drukarka dziedziczy wirtualnie po Papierozene, azeby wykonalo sie poprawne rzutowanie w lini 26 
class Drukarka : virtual public Papierozerne
{
public:
	Drukarka(const Rozdzielczosc & roz) : m_roz(roz) {}
	const Rozdzielczosc & rozdzielczosc() const {return m_roz;}

private:
	Rozdzielczosc m_roz;
};
