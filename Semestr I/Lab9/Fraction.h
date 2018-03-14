#pragma once

//klasa Fraction - reprezentuje ulamek wlasciwy
class Fraction
{
public:
	//konstruktor klasy Fraction - inicjalizuje skladowe obiektu klasy Fraction, oblicza czesc calkowita
	Fraction(const int numerator, const int denominator);

	//metoda wyswietlajaca obiekt klasy Fraction - ulamek - na ekran, nie modyfikuje obiektu
	void Print() const;

	//metoda zwracajaca obiekt klasy Fraction, ktory jest suma dodawania dwoch obiektow klasy Fraction - dwoch ulamkow
	//nie modyfikuje obiektu na recz ktorego jest wywlana 
	Fraction Add(const Fraction frac) const;

	//metoda zwracajaca licznik obiektu na rzecz ktorego jest wywolana - getter
	int Numerator() const;

	//metoda zwracajaca mianownik obiektu na rzecz ktorego jest wywolana - getter
	int Denominator() const;

private:
	//ukryty konstruktor klasy Fraction - nie jest to konieczny zabieg, poniewaz kompilator nie wygeneruje konstruktora domyslnego 
	//poniewaz stworzylismy juz konstruktor dwuargumentowy
	Fraction();

	int _numerator;
	int _denominator;
	int _whole;

};

