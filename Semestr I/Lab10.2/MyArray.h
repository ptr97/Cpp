#pragma once 

class MyArray
{
public:
	//referencja do skladowej m_size - nie pozwala modyfikowac tej skladowej
	const int & size;

	//konstruktor klasy MyArray - inicjalizuje zmienne podanymi argumentami
	MyArray(int *& array, const int arraySize);

	//konstruktor kopiujacy - wykonuje kopiowanie glebokie (deep copy) - alokuje dynamicznie pamiec na tablice intow w nowym obiekcie i kopiuje wartosci 
	MyArray(const MyArray & myArray);

	//metoda zwracajaca referncje do skladowej m_ID, pozwala modyfikowac ta skladowa
	int & id()
	{return m_ID;};

	//metoda zwracajaca wartosc skladowej m_ID
	int id() const
	{return m_ID;};

	//metoda wyswietlajaca tablice na ekran
	void print() const;

	//metoda pozwalajaca zmienic rozmiar tablicy - alokuje ponownie pamiec na stercie
	void resize(const int newSize);

	//metoda pozwalajaca przypisac liczbe w dane miejsce w tablicy
	int & at(const int index)
	{return m_array[index];};

	//metoda zwracajaca wartosc danego indeksu tablicy
	int at(const int index) const
	{return m_array[index];};

	//destruktor zwalniajacy dynamicznie zaalkowana pamiec
	~MyArray();

private:
	//referencja do wskaznika na przekazana dynamicznie zaalokowana tablice
	int *& m_array;

	//wskaznik na dynamicznie zaalokowana tablice 
	int * m_copy;

	//rozmiar dynamicznie zaalokowanej tablicy
	int m_size;

	//ID tablicy
	int m_ID;
};
