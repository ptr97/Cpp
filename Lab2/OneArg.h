#pragma once

//klasa czysto wirtulna reprezentujaca operacje logiczne jednoargumentnowe - udostepnia interfejs dla klas pochodnych
class OneArg
{
public:
	//metoda wirtualna zwracajaca wynik danej operacji logicznej 
	virtual bool result(const bool arg1) const = 0;

	//destruktor wirtualny - w tym przypadku nie robi nic (ale powinien byc wirtualny ponieaz po tej lkasie dziedzicza inne)
	virtual ~OneArg() {}
};
