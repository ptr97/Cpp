/*
 Celem zadania jest napisanie zestawu klas opisujacych ksztalty.
 Jedynymi metodami, ktore ksztalty musza udostepiniac to metoda obliczania 
 powierzhni (area) i metody pozwalajace na wypisanie nazw tych ksztaltow 
 na ekran. Ksztalty mozna grupowac w ksztalty kompozytowe. Taki kompozyt 
 takze powinien byc ksztaltem.
 
 UWAGA: Prosze zwrocic uwage na dealokacje.
 UWAGA: Pusty kompozyt powinien byc rownie funkcjonalny 
 co kompozyt wypelniony ksztaltami.
 
 Kompilowc do pliku: test z opcjami -Wall
 
 */


#include <iostream>
#include "Shapes.h"
#include "Composite.h"

int main() {
  Composite room;
  Composite * wall1 = new Composite();
  Composite * wall2 = new Composite();

  *wall1 <<= new Triangle(3.,2.);
  *wall1 <<= new Square(2.2);
  *wall1 <<= new Circle(1);

  *wall2 <<= new Square(2.);
  *wall2 <<= new Triangle(3.,2.);
  *wall2 <<= new Circle(0.5);
  room <<= wall1;
  room <<= wall2;
  room <<= new Composite();
  std::cout << *wall1 << std::endl;
  std::cout << *wall2 << std::endl;
  std::cout << room << std::endl;
  
  std::cout << wall1->area() << std::endl;
  std::cout << wall2->area() << std::endl;  
  std::cout << room.area() << std::endl;
}
/* wynik
[Triangle Square Circle]
[Square Triangle Circle]
[[Triangle Square Circle] [Square Triangle Circle] []]
10.9815
7.78538
18.7669
 */
