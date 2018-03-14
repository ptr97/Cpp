#pragma once

class Point3D;

//klasa reprezentujaca tablice punktow trojwymiarowych 
class PointCollection
{
public:
	//konstruktor, alokuje dynamiczna pamiec na tablice obiektow klasy Point3D
	PointCollection(const int size);
	
	//metoda przeciazajaca operator [] - zwraca referencje do punktu przechowywanego w tablicy, pozwala modyfikowac pojedynczy punkt w tablicy
	Point3D *& operator[](const int index);
	
	//metoda wypisujaca na ekran punkty znajdujace sie w tablicy
	void Print() const;
	
	//konstruktor kopiujacy, wykonuje "kopiowanie glebokie (deep copy)"
	PointCollection(const PointCollection & ptCollect);

	//destruktor, zwalnia dynamicznie zaalkowana pamiec na tablice obiektow klasy Point3D
	~PointCollection();

private:
	Point3D ** m_array;
	const int m_size;
};
