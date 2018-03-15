#pragma once
#include <iostream>
#include "Wrapper.h"
#include "StringWrapper.h"
#include "FloatWrapper.h"
#include "IntWrapper.h"


//struktura reprezentujaca Wezel w liscie jednokierunkowej, ktory przechowuje wskaznik 
//do klasy czysto wirtualnej Wrapper
struct Node
{
	Node * m_next;
	Wrapper * m_wrapper;
};

//klasa reprezentujaca wektor przechowujacy Wrapper'y
class PVec 
{
public:
	//tworzy obiekt klasy
	PVec() : m_first(NULL) {}

	//dodaje Wrapper na koniec wektora 
	PVec & push_back(Wrapper * wrap);
	
	//zwraca element ktory znajduje sie na miejscu "index" w naszym wektorze (liczac od pierwszego elementu wektora)
	Wrapper & operator[](const int index) const;
	
	//pozwala skopiowac wektor do PUSTEGO wektora (przypisanie do wektora przechowujacego jakies elementy spowoduje wyciek pamieci)
	PVec & operator=(const PVec & vec);
	
	//destruktor ktory zajmuje sie obsluga pamieci przekazanych do wektora elementow - klasa PVec dba o zwalnianie pamieci przekazanych do niej obiektow
	~PVec();

	//funkcja zaprzyjazniona - przeciazony operator << - pozwala wypisywac wektor do standardowego strumienia
	friend std::ostream & operator<<(std::ostream & os, const PVec & vec);

private:
	//wskaznik na pierwszy element listy
	Node * m_first;

};

