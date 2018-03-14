#pragma once
#include "MapDistance.h"

class MapDistance;

class MapPoint 
{
public:
	MapPoint();
	//metoda wyswietla obiekt klasy MapPoint
	void print() const;

	//metoda ustawia pola w obiekcie klasy MapPoint
	void set_coordinates(const double longitude, const double latitude);

	//metoda przyporzadkowuje kazdej instancji klasy unikalny numer ID
	void assign_id();

	//metoda ustawia tylko skladowa longitude obiektu klasy MapPoint 
	void set_longitude(const double longitude);

	//metoda ustawia tylko skladowa lattitude obiektu klasy MapPoint 
	void set_latitude(const double latitude);

	//metoda ta zwraca obiekt ktory jest instancja zaprzyjaznionej klasy MapDistance
	//w klasie tej zawarte sa roznice pomiedzy szerokosciami oraz dlugosciami geograficznymi
	MapDistance distance(const MapPoint& point);

	//metoda zwraca obiekt ktory jest polozony na mapie blizej obiektu na rzecz ktorego zostala wywolana
	MapPoint& closest(MapPoint& point1, MapPoint& point2);

	//zmienna globalna przechowujaca kolejny wolny numer ID
	static int next_free_id;


private:
	double _longitude;
	double _latitude;
	int _id;
};