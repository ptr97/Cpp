// Nazwa pliku wykonywalnego: rtv

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klasy reprezentujace monitor i telewizor
// LCD. Kazde z tych urzadzen wyswietla obraz w inny sposob,
// tzn. dodaje innego rodzaju ramke do obrazu i ma wymiary
// zdefiniowane w programie. Kazde z tych urzadzen moze byc uzyte do
// wyswietlenia z obrazu z komputera lub odtwarzacza DVD (litery zapelniajace
// obraz definiowane sa poprzez konstruktor). 
// UWAGA:
// Informacja ktora jest wyswietlana (oprocz ramki) nie moze znajdowac sie w
// monitorze lub telewizorze.

// W zadaniu mozna korzystac z elementow bilbioteki standardowej
// zwlaszcza klasy std::string, ktora jest dostepna w pliku o nazwie
// "string".

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie rtv. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (archiwum rtv.tar.gz zawierajace dodane pliki, makefile i Main.cpp)
// nalezy wgrac do UPEL.

#include"Main.h"

int main ()
{
  // ------------------------------------------------------------
  Komputer PC('K');
  OdtwarzaczDVD taniOdtwarzacz('D');

  // ------------------------------------------------------------
  const int szerokosc = 14;
  const int wysokosc = 4;
  
  // ------------------------------------------------------------
  Monitor monitorBiurowy(szerokosc, wysokosc);
  const TelewizorLCD telewizorDomowy (17, 6);
  
  // ------------------------------------------------------------
  monitorBiurowy.Wyswietl(PC);
  telewizorDomowy.Wyswietl(PC);

  // ------------------------------------------------------------
  monitorBiurowy.Wyswietl(taniOdtwarzacz);
  telewizorDomowy.Wyswietl(taniOdtwarzacz);
  
  return 0;
}
/*
Polaczono monitor i komputer
--------------
--------------
KKKKKKKKKKKKKK
KKKKKKKKKKKKKK
KKKKKKKKKKKKKK
KKKKKKKKKKKKKK
--------------
--------------


Polaczono telewizor i komputer
_________________
_________________
KKKKKKKKKKKKKKKKK
KKKKKKKKKKKKKKKKK
KKKKKKKKKKKKKKKKK
KKKKKKKKKKKKKKKKK
KKKKKKKKKKKKKKKKK
KKKKKKKKKKKKKKKKK
_________________
_________________


Polaczono monitor i DVD
--------------
--------------
DDDDDDDDDDDDDD
DDDDDDDDDDDDDD
DDDDDDDDDDDDDD
DDDDDDDDDDDDDD
--------------
--------------


Polaczono telewizor i DVD
_________________
_________________
DDDDDDDDDDDDDDDDD
DDDDDDDDDDDDDDDDD
DDDDDDDDDDDDDDDDD
DDDDDDDDDDDDDDDDD
DDDDDDDDDDDDDDDDD
DDDDDDDDDDDDDDDDD
_________________
_________________
*/
