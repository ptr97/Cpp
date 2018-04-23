/* 
 * Celem zadania jest napisanie klasy wyj±tków pomocnych przy sprawdzaniu poprawnosci argumentow.
 * Argumenty sa zawsze typu int.
 * 
 * Mozemy sprawdzic czy te argumenty sa: < <=, > >= w stosunku do podanej granicznej wartosc. 
 * W razie gdy limit jest przekroczony funkcje gt, ge, lt, le powinny generowaæ wyj±tek zawierajacy informacje o problemie.
 *
 * Zadanie mozna rozwiazac na dwa sposoby, z jedna klasa badz wieloma klasami wyjatkow. Oba sa dobre.
 * 
 * Nalezy tez napisac dwa uzyteczne makra pozwalajace na zatrzeymanie wyjatkow w wybranej sekcji kodu.
 */



#include <iostream>
#include "Verifier.h"

void weekDayTest(int x) {
  is(x) <= 7;
  is(x) > 0;

  std::cout << ".. This is day " << x << "\n";
}


void bDayTest(int y, int m, int d) {
  is(y) >= 1900;
  is(y) < 2018;
  is(m) > 0;
  is(m) <= 12;
  is(d) >= 1;
  is(d) < 31;
  
  std::cout << ".. This is b. day " << y << " " << m << " " << d  << "\n";
}



int main() {

  weekDayTest(3);
  try {
    weekDayTest(0);
  } catch(const ArgVerificationFailed& e) {
    std::cout << ".. Handling arg error: " << e << "\n" ;
  }

  bDayTest(1980, 12, 1);
  try {
    bDayTest(2013, 34, 12);
    std::cout << ".. We were born in 2013 \n";
  } catch(const ArgVerificationFailed& e) {
    std::cout << ".. Handling arg error: " << e << "\n";
  }

  SECURED("Test section");
  bDayTest(2016, 11, 02);
  bDayTest(2019, 1, 12);
  ENDSECURED;

  
  
}
/* wynik
.. This is day 3
.. Handling arg error: Argument 0 has to be greater than 0
.. This is b. day 1980 12 1
.. Handling arg error: Argument 34 has to be lower or equal than 12
.. This is b. day 2016 11 2
ArgVerificationFailed in Test section Argument 2019 has to be lower than 2018
 */

