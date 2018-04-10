/* 
 Calem zadanie jest napisanei zespolu klas, ktore moga wspomoc zapisywanie atrybutow klas.
 (Tu to trywialne przypadki gdzie "miejscem zapisu" sa ekran i string.)
 Naturalnym roszerzeniem byloby dodanie metody restoreFrom(Storage&) ale zadanie 
 robi sie zbyt dlugie.

 Kompilowac do pliku test z opcjami -Wall -g
 Dokumentajca to opis dziedzicenia (dlaczego tak a nie inaczej, to wystartczy).
 UWAGA: Do formatowania liczb int i double mozna uzyc sprinf albo jak ktos umie to 
 

 */

#include <iostream>
#include <string>
#include "Recordable.h"
#include "Attribute.h"


class Storage;
using namespace std;
class TestClassA : public Recordable {
public:
  TestClassA( int a, int b, double c) : m_a("a", a), m_b("b", b ), m_c("c", c) {}
  void recordTo(Storage&  storage);
private:
  IntAttr m_a;
  IntAttr m_b;
  DoubleAttr m_c;
};

#include "Storage.h"
void TestClassA::recordTo(Storage& storage) {
  m_a.save(storage);
  m_b.save(storage);
  m_c.save(storage);
}



int main() {

  TestClassA x(0, 1, 9.2);
  TestClassA y(-8, 23, 0.5);
  CoutStorage screen;
  std::string place;
  StringStorage someString(place);

  
  x.recordTo(screen);
  cout << endl;
  x.recordTo(someString); 
  cout << place << endl;

  cout << "---" << endl;

  y.recordTo(screen);
  cout << endl;
  place.clear();
  y.recordTo(someString);

  cout << place << endl;
}
/* wynik
a:0,b:1,c:9.2,
a:0,b:1,c:9.200000,
---
a:-8,b:23,c:0.5,
a:-8,b:23,c:0.500000,

 */
