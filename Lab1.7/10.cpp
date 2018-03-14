/* 
Celem zadania jest napisanie klas odwzorowujacych hierarchie dziedziczenia kontenerow


Tylko metoda name() musi byc wypelniona - pozwalajaca wypisac nazwe klasy.
Reszte metod prosze zaimplementwoac w minimalnym stopniu tak aby program byl poprawny.

Implementujemy hierarchie dziedziczenie dla kontenerow sekwnecyjnych i asocjacyjnych reprezentowanych odpowiednio przez:
 (List i Vector) oraz (SortedTree, SortedMultiTree, HashTree, HashMultiTree). Wersje Multi przechowywac beda duplikaty

UWAGA: brak dokumentacji dyskwalifikuje zadanie - nalezy napisac dlaczego tak a nie inaczej dziedziczymy!!!!

UWAGA: auto_ptr dziala jak zwykly wskaznik tylko ze dba o usuwanie obiektu (smart pointer).

 Prosze kompilowac z opcja -Wall, nie zmieniac tego pliku i nazwac plik wykonywalny 'htest'.


do wypisania nazw klas moanz uzyc ponizszej funkcji
*/

#include <stdlib.h>
#include <cxxabi.h>
#include <string>
#include <iostream>

struct tool{
	static std::string rtti_real_name(const char* name)
	{
		int status;
		char *realname = abi::__cxa_demangle(name, 0, 0, &status);
		std::string n(realname);
		free(realname);
		
		return n;
	};
};

#include <memory>
#include "Containers.h"

using namespace oop;

int main(int argc, char** argv)
{
	Object();

	std::auto_ptr<Object> o  (new Object);
	std::cout << o->name() << "\n";

	o = std::auto_ptr<Object>(new List);
	std::cout << o->name() << "\n";

	o = std::auto_ptr<Object>(new Vector);
	std::cout << o->name() << "\n";

	o = std::auto_ptr<Object>(new SortedTree);
	std::cout << o->name() << "\n";


	o = std::auto_ptr<Object>(new SortedMultiTree);
	std::cout << o->name() << "\n";

	o = std::auto_ptr<Object>(new HashTree);
	std::cout << o->name() << "\n";

	o = std::auto_ptr<Object>(new HashMultiTree);
	std::cout << o->name() << "\n";


#ifdef COMPILE_ERROR 
	//ustawienie tej dyrektywy generuje blad kompilacji w kazdej lini mimo iz typy stojace za new istnieja w hierachi dziedziczenia!
	// prosze do makefile dopisac target make fail, ktory dodaje flage -DCOMPILE_ERROR
	o = std::auto_ptr<Object>(new Container);
	o = std::auto_ptr<Object>(new SquenceContainer);		
	o = std::auto_ptr<Object>(new TreeContainer);
	o = std::auto_ptr<Object>(new SortedTreeContainer);
	o = std::auto_ptr<Object>(new HashTreeContainer);
#endif

	std::auto_ptr<SequenceContainer> s  (new List);
	s = std::auto_ptr<SequenceContainer>(new Vector);
	std::cout << s->name() << "\n";
			
	s->push_front(o.get()); //imituje wstawienie na poczatek
	s->push_back(o.get()); //imituje wstawienie na koniec

	std::auto_ptr<Container> c  (new SortedTree);
	c = std::auto_ptr<Container>(new SortedMultiTree);
	c = std::auto_ptr<Container>(new HashTree);
	c = std::auto_ptr<Container>(new HashMultiTree);
	std::cout << c->name() << "\n";
	
	c->size();  //zwraca ilosc elementow
	c->empty(); //zwraca czy kontener jest pusty
	c->insert(s.get()); //imituje wstawienie 
}

/* Wynik
oop::Object
oop::List
oop::Vector
oop::SortedTree
oop::SortedMultiTree
oop::HashTree
oop::HashMultiTree
oop::Vector
oop::HashMultiTree
*/
