#pragma once

#include <iostream>

//klasa reprezentujaca punkt trojwymiarowy
class Point3D
{
public:
	//wyliczenie pozwalajace nam sie w ladny sposob odwolywac do poszczegolnych wspolrzednych punktu
	enum
	{
		X = 0, Y = 1, Z = 2
	};

	//konstruktor tworzacy obiekt klasy Point3D, inicjalizuje wspolrzedne punktu podanymi argumentami
	Point3D(const double x, const double y, const double z);

	//funkcja globalna zaprzyjazniona z klasa przeciazajaca operator << - wypisuje punkt na ekran
	friend std::ostream & operator<<(std::ostream & os, const Point3D & point);

	//przeciazony operator [] - pozwala sie odwolac do danej wspolrzednej, zwraca do niej referencje przez co mozna ja modyfikowac
	double & operator[](const int number);

	//przeciazony operator [] - zwraca wartosc wspolrzednej o numerze number, tylko do odczytu 
	double operator[](const int number) const;

private:
	//tablica w ktorej przechowywane sa kolejne wspolrzedne punktu
	double m_coordinate[3];
};

