#pragma once

class MapDistance
{
public:
	//konstruktor domyslny
	//MapDistance();

	//konstruktor inicjalizujacy skladowe klasy danymi parametrami
	MapDistance(double diff_longitude, double diff_latitude);

	//metoda wyswietla skladowe klasy
	void print();

private:
	//roznica dlugosci geograficznej
	double _diff_longitude;
	//roznica szerokosci geograficznej
	double _diff_latitude;
};

