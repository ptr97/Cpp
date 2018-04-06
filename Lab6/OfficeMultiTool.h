#pragma once
#include "Rozdzielczosc.h"
#include "Drukarka.h"
#include "Ksero.h"
#include "Skaner.h"

//klasa ta dziedziczy po wszystkich wymienionych urzadzeniach, aby moglo sie wykonac wszystko w liniach od 29 do 32
class OfficeMultiTool : public Skaner, public Drukarka, public Ksero
{
public:
	OfficeMultiTool(const Rozdzielczosc & roz1, const Rozdzielczosc & roz2) : Urzadzenie(), Papierozerne(), Skaner(roz2), Drukarka(roz1), Ksero() {}
};

