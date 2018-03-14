/*
  Celem zadania jest napisanie czesci wykonawczej wyrazenia regularnego.
  Do implementacji potrzeba tylko elementu sprawdzajacego czy:
  litera jest duza, 
  czy litera jest zgodna ze wzorcem, 
  badz z zakresu znakow, badz elementu akceptujcego znaki az 
  do wystapienia znaku. 
  
  Rozwiazanie zadania polega na wytworzeniu zestawu klas, 
  jednej dla kazdego testu. 
  UWAGA: Rozwiazanie mozna to oczywiscie zoptymlalizowac 
         poprzez ponowne uzycie klas.
  UWAGA/PRZYPOMNINEIE: Zachowanie polimorficzne metod zachodzi
  gdy sa wywolywana na rzecz wskaznikow badz referncji do obiektow.
  
  UWAGA: Prosze zadbac o zwolnienie pamieci.

 */



#include <iostream>
#include "RegEx.h"
#include "Checkers.h"



int main() {
  using namespace std;
  RegEx r1,r2;
  r1(capitalLetter()) // dowolna duza litera
    (letter('a')) // litera a
    (letter('b')) // litera b
    (letterFromRange('a', 'k'));
  r2(anythingUntilLetter('.'))(letterFromRange('b','f'));

  cout << r1.elements() << " " << r1.match("kopalnia")  << endl;
  cout << r1.elements() << " " << r1.match("Fabde")  << endl;

  cout << r2.elements() << " " << r2.match("Kopalnia.bea")  << endl;
  cout << r2.elements() << " " << r2.match("ok.dane")  << endl;  
  cout << r2.elements() << " " << r2.match("ok.r")  << endl;
}
/* wynik
CapitalLetter() Letter(a) Letter(b) InRange(a,k)  0
CapitalLetter() Letter(a) Letter(b) InRange(a,k)  1
UntilLetter(.) InRange(b,f)  1
UntilLetter(.) InRange(b,f)  1
UntilLetter(.) InRange(b,f)  0   
 */
