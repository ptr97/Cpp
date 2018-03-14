#pragma once

class Grade;

class Student
{
public:
	//konstruktor klasy Student, inicjalizuje wszystkie pola klasy
	Student();

	//metoda ustawiajaca numer ID studenta 
	void setID(const int & ID);

	//metoda wyswietlajaca na ekran skladowe obiektu klasy Student
	void print() const;

	//metoda zwracajaca referencje do wskaznika na tablice ocen
	int *& Grades();

	//metoda zwracajaca adres do numeru ID studenta
	int * ID();

	//metoda zwracajaca ilosc obecnych ocen studenta, pozwala ja rowniez zmienic
	int & GradesCounter();

	//destruktor zwalniajacy dynamicznie zaalokowana pamiec dla tablicy ocen 
	~Student();


private:


	//zmienna przechowuje ID studenta
	int m_ID;

	//wskaznik do alokowanej dynamicznie tablicy na oceny studenta
	int * m_grades;

	//zmienna przechowujaca ilosc obecnych ocen studenta
	int m_gradesCounter;
};

