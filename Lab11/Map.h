#pragma once

#include <stdexcept>
#include <iostream>
#include <vector>


// szablon klasy ktora implementuje kontener asocjacyjny - mape
// argument szablonu K to typ klucza, a V to typ wartosci "przechowywanej" 
// pod danym kluczem
template <typename K, typename V>
class Map
{
public:
	// metoda wstawiajaca na koniec mapy wartosc 'val' typu V
	// pod kluczem 'key' typu K
	void insert(K key, V val);
	
	// metoda wypisujaca na ekran wszystkie elementy znajdujace sie w mapie
	// przed wypisaniem elementu wypisuje na ekran 'prefix'
	// metoda ma zlozonosc czasowa stala rzedu n
	void print(const char * prefix) const;

	// przeciazony operator [], ktory nie jest staly,
	// udostepnia interfejs modyfikowania wartosci obiektu znajdujacego sie pod kluczem 'key'
	// jesli w mapie nie ma klucza 'key' to do mapy dodawany jest nowy obiekt pod kluczem 'key'
	// oraz jest zwracana referencja do niego -  pozwalajaca go modyfikowac
	V & operator[](K key);

	// przeciazony staly operator [], zwraca wartosc obiektu znajdujacego sie w mapie
	// jesli w mapie nie ma obiektu zmapowanego na klucz 'key', to wyrzucany jest wyjatek
	// std::invalid_argument
	const V & operator[](K key) const throw(std::invalid_argument);

	// metoda ktora udostepnia interfejs informujacy o tym czy w mapie znajduje sie 
	// klucz 'key', jesli tak to zwraca true, jesli klucza nie ma - false
	bool contains(K key) const;

private:
	// wewnetrzna struktura przechowujaca obiekt i jego klucz na ktory jest rzutowany
	struct Meta
	{
		// konstruktor pozwalajaca zainicjalizowac tylko klucz
		Meta(K key) : m_key(key) {}

		// konstruktor inicjalizujacy klucz i obiekt na ktory jest mapowany
		Meta(K key, V val) : m_key(key), m_val(val) {}
		
		// klucz
		K m_key;

		// obiekt
		V m_val;
	};

	// wektor przechowywujacy wszystkie struktury mapujace
	std::vector<Meta> m_values;
};

template <typename K, typename V>
void Map<K, V>::insert(K key, V val)
{
	Map<K, V>::Meta record(key, val);

	m_values.emplace_back(record);
}

template <typename K, typename V>
void Map<K, V>::print(const char * prefix) const
{
	for(const Meta & meta : m_values)
		std::cout << prefix << " k: " << meta.m_key << " v: " << meta.m_val << std::endl;
}

template <typename K, typename V>
V & Map<K, V>::operator[](K key)
{
	bool ifFound = false;
	unsigned index = 0;

	for(unsigned i = 0; i < m_values.size(); ++i)
	{
		if(key == m_values[i].m_key)
		{
			ifFound = true;
			index = i;
		}
	}

	if(ifFound)
	{
		return m_values[index].m_val;
	}
	else
	{
		Map<K, V>::Meta record(key);

		m_values.emplace_back(record);
		return m_values[m_values.size() - 1].m_val;
	}
}

template <typename K, typename V>
const V & Map<K, V>::operator[](K key) const throw(std::invalid_argument)
{
	bool ifFound = false;
	unsigned index = 0;

	for(unsigned i = 0; i < m_values.size(); ++i)
	{
		if(key == m_values[i].m_key)
		{
			ifFound = true;
			index = i;
		}
	}

	if(ifFound)
		return m_values[index].m_val;

	throw std::invalid_argument("Klucz nieodpowiedni");
}

template <typename K, typename V>
bool Map<K, V>::contains(K key) const
{
	bool ifFound = false;

	for(const Meta & meta : m_values)
	{
		if(key == meta.m_key)
			ifFound = true;
	}

	return ifFound;
}
