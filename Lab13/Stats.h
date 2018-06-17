#pragma once
#include <fstream>
#include <map>


// klasa sluzaca do zbierania statystyk naszego kodu,
// do jej funkcjonalnosci naleza: liczenie ile razy powtorzylo sie kazde slowo
// oraz ile razy powtorzyla sie kazda litera
class Stats
{
public:
	// konstruktor ktory tworzy klase Stats z mapy, ktora mapuje wystepujacy ciag znakow
	// na ilosc jego wystapien 
	Stats(const std::map<std::string, int> & counter) : m_counter(counter) {}

	// funkcja statyczna ktora zlicza wystapienia wszystkich wyrazow 
	// w pliku o nazwie fileName i tworzy nowy obiekt typu Stats 
	static Stats scanForWords(const std::string & fileName);

	// funkcja statyczna ktora zlicza wystapienia wszystkich znakow 
	// w pliku o nazwie fileName i tworzy nowy obiekt typu Stats 
	static Stats scanForChars(const std::string & fileName);

	// metoda zwracajaca mape, w ktorej sa zmapowne ciagi znakow ktore wystapily na ilosc ich wystapien
	const std::map<std::string, int> & details() const {return m_counter;}

	// zaprzyjazniony operator<< ktory wypisuje na strumien wyjsciowy ile roznych wyrazow/znakow
	// wystapilo w naszym pliku
	friend std::ostream & operator<<(std::ostream & os, const Stats & stats);

private:
	// prywatna mapa mapujaca ciag znakow na ilosc jego wystapien
	std::map<std::string, int> m_counter;
};

// przeciazony operator<< sluzacy do wypisywania wszystkich elementow mapy typu string -> int
std::ostream & operator<<(std::ostream & os, const std::map<std::string, int> & map);
