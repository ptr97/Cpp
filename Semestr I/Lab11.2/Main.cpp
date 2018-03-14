#include <iostream>
#include <sstream> 
#include "Main.h"


int main()
{
	const Wektor3D wektor1(2, 5, 7);
	const WektorTransponowany3D wektor2(9, 5, 3);

	const Wektor3D suma = wektor1 / wektor2; // operator+(wektor1, wektor2);

	wektor1.Wypisz();
	wektor2.Wypisz();

	std::cout << "Suma \n";

	suma.Wypisz();

	std::cout << "=======MACIERZ=========\n";

	Macierz macierzSuma = wektor1 * wektor2;

	macierzSuma.Wypisz();

	
	double tab[3][3] = {0};


	Macierz macierzKopia(tab, 3);
	macierzKopia = macierzSuma;

	std::cout << "=========KOPIA========\n";
	macierzKopia.Wypisz();

	std::cout << "=========PRZECIAZENIA operator()============\n";

	WektorTransponowany3D wiersz = macierzKopia(2);

	wiersz.Wypisz();

	double liczba = macierzKopia(0, 2);
	std::cout << "Liczba : " << liczba << std::endl;

	std::cout << "================GRZESIU ================\n";

	WektorTransponowany3D predkoscTrans;
	Wektor3D predkosc1;
	predkosc1 << predkoscTrans;

	std::cout << "predkosc1: " << predkosc1 << std::endl;

	std::cout << "===========wskazniki================\n\n";

	Wektor3D * wskaznik = new Wektor3D;

	delete wskaznik;

	std::cout << "============inkrementacja=================\n\n";

	Wektor3D testInkrementacji(8, 7, 5);
	testInkrementacji.Wypisz();

	++testInkrementacji;
	std::cout << "++testInkrementacji\n";
	testInkrementacji.Wypisz();

	std::cout << testInkrementacji++;
	std::cout << "testInkrementacji++\n";
	testInkrementacji.Wypisz();


	return 0;
}

