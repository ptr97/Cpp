#pragma once
#include <iostream>

class Obserwator
{
public:
	virtual void PrzetwarzajDane(const int dane) = 0;

};



//////////////////////////////////////////////////////
class ObserwatorLicznik : public Obserwator
{
public:
	ObserwatorLicznik() : Obserwator(), m_suma(0) {}
	virtual void PrzetwarzajDane(const int dane) {m_suma += dane;}
	int suma() const {return m_suma;}

private:
	int m_suma;
};



//////////////////////////////////////////////////////
class ObserwatorWypisywacz : public Obserwator
{
public:
	virtual void PrzetwarzajDane(const int dane) {std::cout << " " << dane;}

private:

};

