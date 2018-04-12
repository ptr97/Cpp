#pragma once
//zmieniona nazwa pliku .h z uwagi na dolaczone pliki do main'a oraz chec rozmieszczenia kazdej z klas w osobnym pliku

// klasa bazowa Obserwator, ktora udostepnia interfejs do przetwarzania danych przez klasy pochodne
class Obserwator
{
public:
	//wirtualna metoda udostepniajaca interfejs przetwarzajacy dane
	virtual void przetworzDane(const int dane) = 0;

	//wirtualny destruktor, poniewaz po tej klasie dziedzicza inne
	virtual ~Obserwator() {}
};