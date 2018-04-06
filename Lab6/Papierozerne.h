#pragma once
#include "Rozdzielczosc.h"
#include "Urzadzenie.h"

//klasa dziedziczy po Urzadzenie, wymaga tego zastosowanie tej klasy bazowej Urzadzenie przy Skanerze
class Papierozerne : virtual public Urzadzenie
{
public:
	virtual ~Papierozerne() {}
};
