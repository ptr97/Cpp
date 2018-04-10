/*
  Celem zadania jest napisanie klasy StatusCode, ktora wspomaga
  programiste w pracy w syetemie gdzie nalezy sprawdzac kody bledow. 
  Mianowicie obiekty klasy StatusCode maja dzialc
  w taki sposob:  Podczas konstrukcji pobieraja kod bledu, funkcje
  potwierdzajaca ze kod bledu wskazuje na poprawna wartosc i jakas informacje tekstowa.  
  Jesli na tym obiekcie nigdy nie zostanie wywolana metoda isok() to powinien 
  zostac wyrzucaony wyjatek podczas destrukcji tego obiektu.  
  Wyjatek nie powinien sie pojawic jesli metoda isok() zostala wywolana.
  Cala zabawa pojawia sie przy operatorze przypisania zwlaszcza gdy jego argument 
  jest typu const.

  UWAGA: Funkcje gtzero mozna zaimplementowac nastepujaco:
  bool gtzero(int v) {
    return v >= 0;
  }
  Aby usymetryzowac implementacje mozna dopisac podobna fukcje zwracajaca zawsze wartosc true.
  Prosz zwrocic uwage ze tych funkcji bedziemy uzywac dopiero w momencie wywolania metody isok().


  Wyjatek wyrzucony powinien sie nazwyac UncheckedStatusCode 
  i musi przechowac informacje z wczesniej zawarta w obiekcie StatusCode.
  
  Do kompletu nalzey napisac  UncheckedStausHandler obslugujacy taki wyjatek 
  i wyjatki standardowe.
 */

#include <iostream>
#include "StatusCode.h"

const StatusCode test1( int val) {
  // ten status jest OK jesli va >= 0 i jest !OK w przeciwnym razie
  // Konstruktor pobiera wartosc, funkcje/funktor sprawdzajaca i info
  return StatusCode( val, StatusCodeCheckers::gtzero, "from test1");  
}

StatusCode test2(int val) {
  StatusCode sc;
  sc = test1(val);
  return sc;
}

using namespace std;
int main() {
  try {
    {
      StatusCode s;
    }
    StatusCode sc = test2(1);  // wywolanie bezproblemowe
    if ( sc.isok() )
      cout << "ok " << sc.status() << endl;
    else
      cout << "not ok " << sc.status() << endl;
    
    
    sc = test2(-1);  // wywolanie z bledem
    if ( sc.isok() )
      cout << "ok " << sc.status() << endl;
    else
      cout << "not ok " << sc.status() << endl;

    test2(1); // nie sprawdzamy kodu bledu wiec dostajemy wyjatek
    
    
  } catch (...) {
    UncheckedStausHandler::handle();
  }

  try {
    throw std::runtime_error("jakis blad");
  } catch(...) {
    UncheckedStausHandler::handle();
  }
  
  
  
}
/* wynik
ok 1
not ok -1
..Handling UncheckedStatusCode from test1
..Handling std::exception jakis blad
 */
