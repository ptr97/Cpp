#pragma once

//klasa czysto wirtulna reprezentujaca operacje logiczne dwuargumentnowe - udostepnia interfejs dla klas pochodnych
class TwoArg
{
public:
	//metoda wirtualna zwracajaca wynik danej operacji logicznej 
	virtual bool result(const bool arg1, const bool arg2) const = 0;

	//destruktor wirtualny - w tym przypadku nie robi nic (ale powinien byc wirtualny ponieaz po tej lkasie dziedzicza inne)
	virtual ~TwoArg() {}
};
