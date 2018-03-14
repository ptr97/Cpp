#pragma once
#include "StudentsList.h"

//deklaracja wyprzedzajaca klasy StudentsList
class StudentsList;

//klasa Student
class Student
{
public:
	//zmienna statyczna pozwalajaca nam ustalic ID studenta
	static int nextID;

	//konstruktor klasy Student - inicjalizuje skladowe obiektu
	Student(const char * name, const char * surname);

	//metoda wypisujaca na ekran dane studenta
	void Print() const;

	//metoda zwracajaca wskaznik do listy w ktorej znajduje sie obiekt na rzecz ktorego jest ona wywolana
	StudentsList* ParentList() const;

	//metoda zwracajaca referencje do wskaznika _next - pozwala ustawic ta wartosc z poziomu implementacji klasy StudentsList
	Student*& Next();

	//metoda zwracajaca referencje do wskaznia _parentList - tak samo pozwala zainicjalizowac ta skladowa w klasie StudentsList
	StudentsList*& ParentListRef();

	//destruktor
	~Student();
	
private:

	//metoda zwracajaca referencje do imienia, pozwala ona na zwolnienie tej skladowej w destruktorze klasy StudentsList metoda pierwsza 
	char*& Name();

	//metoda zwracajaca referencje do nazwiska, pozwala ona na zwolnienie tej skladowej w destruktorze klasy StudentsList metoda pierwsza 
	char*& Surname();

	int _id;
	char * _name;
	char * _surname;

	//wskaznik do nastepnego obiektu klasy Student
	Student * _next;

	//wskaznik do listy w ktorej znajduje sie obiekt klasy Student
	StudentsList * _parentList;
};
