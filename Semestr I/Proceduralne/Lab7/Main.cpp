// Nazwa pliku wykonywalnego: Fraction

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac strukture reprezentujaca ulamek oraz funkcje
// wykonujace na niej operacje oraz obslugujace tablice ulamkow.

// Komentarze w kodzie pokazuja jakie wyjscie powinna generowac dana
// linia.

// Prosze zwrocic uwage na dobre zarzadzanie pamiecia.

// UWAGA !!!
// Do rozwiazania zadani nie wolno korzystac z zadnych funkcji z
// biblioteki standardowej oprocz cout i endl.

// UWAGA !!!
// Program powinien byc zoptymalizowany pod wzgledem zarzadzania
// pamiecia, tzn. nie powinno byc zbednej alokacji pamieci.

// UWAGA !!!
// Do rozwiazania zadania TRZEBA wykorzystac pliki Createors.cpp i
// Destroyers.cpp, do ktorych mozna dopisywac kod, ale nie mozna
// usuwac juz istniejacego.

// Pliku Main.cpp, nie wolno modyfikowac. 

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie podanej na poczatku tego pliku. Program nalezy kompilowac
// z flagami -Wall -Wextra -pedantic -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile)

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy wgrac
// do UPEL: upel.agh.edu.pl/wfiis/course/view.php?id=22

#include "Main.h"

#include<iostream>

int main ()
{
  Fraction* first = CreateFraction (1, 2);
  Print (first);		// 1/2

  Fraction* second = 0;
  SetFraction (&second, 5, 3);
  Print (second);		// 1 2/3

  Fraction sumFirstSecond = Sum (first, second);
  Print (&sumFirstSecond);	// 2 1/6

  Fraction** array = CreateArray();
  AddToArray(&array, first);
  AddToArray(&array, second);
  CreateAddToArray(&array, 13, 29);

  std::cout<<"\n=== First Print ===\n";
  PrintArray (array);		// Array size: 3
                                // 1: 1/2
                                // 2: 1 2/3
                                // 3: 13/29


  std::cout<<"\n=== Second Print ===\n";
  PrintArray (array);		// Array size: 3
                                // 1: 1/2
                                // 2: 1 2/3
                                // 3: 13/29


  std::cout<<"\n=== Third Print ===\n";
  AddToArray(&array, &sumFirstSecond);
  CreateAddToArray(&array, 8, 11);
  PrintArray (array);		// Array size: 5
                                // 1: 1/2
                                // 2: 1 2/3
                                // 3: 13/29
                                // 4: 2 1/6
                                // 5: 8/11

  ClearArray(&array);

  DestroyFraction (first);
  DestroyFraction (second);

  PrintArray (array);		// (nothing)

  return 0;
}
/* wynik dzialania programu:
1/2
1 2/3
2 1/6

=== First Print ===
Array size: 3
1: 1/2
2: 1 2/3
3: 13/29

=== Second Print ===
Array size: 3
1: 1/2
2: 1 2/3
3: 13/29

=== Third Print ===
Array size: 5
1: 1/2
2: 1 2/3
3: 13/29
4: 2 1/6
5: 8/11
*/
