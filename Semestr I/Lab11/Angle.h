#pragma once

//klasa Angle przechowujaca kat w stopniach
class Angle
{
public:
	//konstruktor tworzacy obiekt klasy Angle inicjalizujacy obiekt radianami 
	explicit Angle(const double radian);

	//konstruktor kopiujacy - tworzy obiekt zainicjalizowany katem z obiektu kopiujacaego
	Angle(const Angle& angle);

	//metoda zwracajaca przechowywany w obiekcie kat w radianach
	double rad() const;

	//metoda zwracajaca przechowywany w obiekcie kat w stopniach
	double deg() const;

	//metoda zwracajaca referencje do przechowywanego w obiekcie kata, pozwala go zmienic
	double & deg();

	//metoda statyczna liczaca odleglosc pomiedzy katami 
	static Angle distance(const Angle & val1, const Angle & val2);

	//metoda rzutujaca obiekt typu Angle na wartosc typu int
	operator int() const;


private:
	//kat w stopniach
	double m_degrees;
};

