/* 
Celem zadania jest napisanie klas odwzorowujacych hierarchie kontenerow (zdefiniowana relacja jest-rodzaju) 

Implementujemy hierarchie dla kontenerow sekwnecyjnych i asocjacyjnych reprezentowanych odpowiednio przez:
(List i Vector) oraz (SortedTree, SortedMultiTree, HashTree, HashMultiTree).


Metod nie wplywajace na wynik prosze zaimplementwoac w minimalnym stopniu tak aby program byl poprawny.


Uwaga brak dokumentacji dyskwalifikuje zadanie - nalezy napisac dlaczego tak a nie inaczej dziedziczymy!!!!

Do zadanai dolaczony jest makefile, ktory poza targetem "all" posiada target "faill". 
W tej kompilacji wlaczone zostaja linie wystepujace w polowie testu i te linie *musza* powodowac blad kompilacji.

*/
#include <stdlib.h>
#include <cxxabi.h>
#include <string>
#include <iostream>


#include "Containers.h"

using namespace oop;

int main(int argc, char** argv)
{
	Object();
	Object* o;
	{
	  o = new Object;
	  std::cout << o->name() << "\n";
	  delete o;
	}
	{
	  o = new List;
	  std::cout << o->name() << "\n";
	  delete o;
	}
	{
	  o = new Vector;
	  std::cout << o->name() << "\n";
	  delete o;
	}
	{
	  o = new SortedTree;
	  std::cout << o->name() << "\n";
	  delete o;
	}
	{
	  o = new SortedMultiTree;
	  std::cout << o->name() << "\n";
	}
	{
	  o = new HashTree;
	  std::cout << o->name() << "\n";
	  delete o;
	}
	{
	  o = new HashMultiTree;
	  std::cout << o->name() << "\n";
	  delete o;
	}
	std::cout << "---------------------\n";

#ifdef COMPILE_ERROR 
	//ustawienie tej dyrektywy generuje blad kompilacji w kazdej lini mimo iz typy stojace za new istnieja w hierachi dziedziczenia!
	o = new Container;
	o = new SequenceContainer;		
	o = new TreeContainer;		
	o = new SortedTreeContainer;				
	o = new HashTreeContainer;				
#endif
	
	SequenceContainer* s(new List);
	delete s;
	s = new Vector;
	std::cout << s->name() << "\n";
	{
	  Object *o = new List;
	  s->push_front(o); //imituje wstawienie na poczatek (implementacja pusta)
	  s->push_back(o); //imituje wstawienie na koniec
	  delete o;
	}
	delete s;
	std::cout << "---------------------\n";
	{
	  Container* c  (new SortedTree);
	  delete c;
	  c = new SortedMultiTree;
	  delete c;
	  c = new HashTree;
	  delete c;
	  c = new HashMultiTree;
	  std::cout << c->name() << "\n";


	  c->size();  //zwraca ilosc elementow
	  c->empty(); //zwraca czy kontener jest pusty
	  {	    
	    c->insert(c); //imituje wstawienie
	  }
	  //(lub rozpoczecie wyszykiwania miejsca wstawienia) do dowolnego kontenera wartosci, domyslnie na pozycji 0.
	  delete c;
	}
}

/*Wynik dzilania
oop::~Object
oop::Object
oop::~Object
oop::List
oop::~List
oop::~SequenceContainer
oop::~Container
oop::~Object
oop::Vector
oop::~Vector
oop::~SequenceContainer
oop::~Container
oop::~Object
oop::SortedTree
oop::~SortedTree
oop::~SortedTreeContainer
oop::~Container
oop::~Object
oop::SortedMultiTree
oop::HashTree
oop::~HashTree
oop::~HashTreeContainer
oop::~Container
oop::~Object
oop::HashMultiTree
oop::~HashMultiTree
oop::~HashTreeContainer
oop::~Container
oop::~Object
---------------------
oop::~List
oop::~SequenceContainer
oop::~Container
oop::~Object
oop::Vector
oop::~List
oop::~SequenceContainer
oop::~Container
oop::~Object
oop::~Vector
oop::~SequenceContainer
oop::~Container
oop::~Object
---------------------
oop::~SortedTree
oop::~SortedTreeContainer
oop::~Container
oop::~Object
oop::~SortedMultiTree
oop::~SortedTreeContainer
oop::~Container
oop::~Object
oop::~HashTree
oop::~HashTreeContainer
oop::~Container
oop::~Object
oop::HashMultiTree
oop::~HashMultiTree
oop::~HashTreeContainer
oop::~Container
oop::~Object
*/
