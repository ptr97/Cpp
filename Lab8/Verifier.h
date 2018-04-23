#pragma once
#include <string>
#include <iostream>


// makro definiujace blok o nazwie X, ktory odpowiada za obslugiwanie wyjatkow typu ArgVerificationFailed
#define SECURED(X) std::string blockName = X; try{ 
#define ENDSECURED } catch(const ArgVerificationFailed& e){std::cout << "ArgVerificationFailed in " << blockName << " " << e << std::endl;}


// klasa reprezentujaca blad powstaly przy sprawdzaniu - validacji - daty 
class ArgVerificationFailed
{
public:
	// konstruktor klasy - inicjalizuje pole ktore przechowuje informacje o wyjatkowej sytuacji
	ArgVerificationFailed(std::string errorName) : m_error(errorName) {}

	// zaprzyjazniony operator wypisania ktory wypisuje tresc wyjatku na standardowe wyjscie
	friend std::ostream & operator<<(std::ostream & os, const ArgVerificationFailed & avf);

private:
	// pole ktore przechowuje informacje tekstowa o wyjatkowej sytuacji, ktora zaszla
	// jest stala poniwaz informacje o bledzie jaki zaszedl powinny byc stale i nie powinnismy ich modyfikowac
	const std::string m_error;
};


// klasa validujaca - sprawdzajaca poprawnosc danych
class is
{
public:
	// konstruktor zapamietuje przekazana wartosc
	is(const int x) : m_value(x) {}

	// wszystkie ponizsze przeciazone operatory sluza do porownania przekazanej im wartosci z wartoscia zapamietana w naszej klasie
	// jesli zmienna toValidate nie spelnia warunku porowania z wartoscia ktora zostala zapamietana,
	// to wyrzucany jest wyjatek typu ArgVerificationFailed - do ktorego przekazywana jest informacja o tym jakie wartosci byly porownywane
	// oraz jaki warunek nie zostal spelniony
	void operator<=(const int toValidate) const;
	void operator<(const int toValidate) const;
	void operator>=(const int toValidate) const;
	void operator>(const int toValidate) const;

private:
	// zapamietana wartosc przy konstrukcji obiektu
	const int m_value;
};
