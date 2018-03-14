#pragma once

class Student;


class Grade
{
public:
	//konstruktor klasy Grade, incjalizuje wszystkie skladowe klasy
	Grade(const int grade, Student& student);

	//metoda wyswietlajaca klase na ekran
	void print() const;

private:
	//zmienna przechowuje wartosc oceny
	int m_value;

	// zmienna przechowuje wskaznik do wartosci ID studenta ktory dostal taka ocene
	int * m_whose;

};
