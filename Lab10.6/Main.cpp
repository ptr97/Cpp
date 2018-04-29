// Nazwa pliku wykonywalnego: Potegi

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// UWAGA!
// Wszystkie obliczenia powinny wykonywac sie na etapie
// kompilacji. Jezeli obliczenia nie beda wykonywane w czasie
// kompilacji, rozwiazanie bedzie nie na temat, a wiec zostanie
// ocenione na 0 punktow.

// UWAGA!
// Po odkomentowaniu ERROR powinien pojawic sie blad kompilacji, ktory
// w swoim komunikacie bedzie zawieral tresc
// "TooLargeNumberMustBeSmallerThan10".

// Prosze napisac szablon Power, ktory na etapie kompilacji oblicza
// potege danej liczby. Podstawy poteg jak i wykladniki sa liczbami
// calkowitymi, ktore moga przyjmowac wartosci dodatnie i ujemne. W
// przypadku podania wykladnika potegi rownego conajmniej 10, powinien
// pojawic sie blad kompilacji z informacja, ze wykladnik jest zbyt
// duzy.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy
// wgrac do UPEL.

#include"Main.h"
#include<iostream>

// #define ERROR

int main ()
{
  std::cout<<"Values\n";
  std::cout<<"3^4 = "<<Power<3, 4>::Value<<"\n";
  std::cout<<"3^(-4) = "<<Power<3, -4>::Value<<"\n";
  std::cout<<"4^0 = "<<Power<4, 0>::Value<<"\n";
  std::cout<<"(-2)^3 = "<<Power<-2, 3>::Value<<"\n";

#ifdef ERROR
  std::cout<<"1^10 = "<<Power<1, 10>::Value<<"\n";
#endif

  return 0;
}
/*
Values
3^4 = 81
3^(-4) = 0
4^0 = 1
(-2)^3 = -8
*/
