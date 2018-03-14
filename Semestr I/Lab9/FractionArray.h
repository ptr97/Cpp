#pragma once
#include "Fraction.h"

class Fraction;


class FractionArray
{
public:
	//konstruktor klasy FractionArray - alokuje pamiec na tablice wskaznikow do obiektow typu Fraction o rozmiarze size
	FractionArray(const int size);

	//metooda wyswietlajaca na ekran tablice ulamkow
	void Print() const;

	//metoda dodaje do tablicy ulamek
	void AddFration(const int numerator, const int denominator);

	//metoda dodaje do siebie wszystkie ulamki w tablicy, zwraca obiekt klasy Fraction, ktory jest wynikiem dodawania
	Fraction Sum() const;

	//destruktor klasy FractionArray
	~FractionArray();


private:
	//rozmiar tablicy ktora chcemy zaalokowac
	const int _size;

	//wskaznik do tablicy wskaznikow do obiektow klasy Fraction - ulamkow
	Fraction ** _frac;

	//zmienna przechowujaca obecna ilosc przechowywancyh w tablicy wskaznikow do obiektow klasy Fraction
	int _fracCounter;
};

