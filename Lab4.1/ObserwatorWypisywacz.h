#pragma once
#include "Obserwator.h"
#include <iostream>

class ObserwatorWypisywacz : public ObserwatorBaza
{
public:
	virtual void PrzetwarzajDane(const int dane) {std::cout << " " << dane;}

};

