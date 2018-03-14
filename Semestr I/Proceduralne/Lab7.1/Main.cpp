// Nazwa pliku wykonywalnego: Fraction

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac strukture reprezentujaca ulamek oraz funkcje
// wykonujace na niej operacje oraz obslugujace tablice ulamkow.

// Komentarze w kodzie pokazuja jakie wyjscie powinna generowac dana
// linia.

// UWAGA !!!
// Prosze zwrocic uwage na dobre zarzadzanie pamiecia. Za wycieki
// pamieci beda odebrane ok. 2 punkty.

// UWAGA !!!
// Do rozwiazania zadania nie wolno korzystac z zadnych funkcji z
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

  Fraction* second = CreateFraction (5, 3);
  Print (second);		// 1 2/3

  Fraction* sumFirstSecond = Sum (first, second);
  Print (sumFirstSecond);	// 2 1/6

  Fraction* diffFirstSecond = Difference(first, second);
  Print (diffFirstSecond);	// -1 1/6

  Fraction* prodFirstSecond = Product(first, second);
  Print (prodFirstSecond);	// 5/6

  Clear();

  return 0;
}
/* wynik dzialania programu:
1/2
1 2/3
2 1/6
-1 1/6
5/6
*/
