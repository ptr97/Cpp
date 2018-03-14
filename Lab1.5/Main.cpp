// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Proszę napisać listę, do której będzie można dodawać obiekty
// określonych typów.

// UWAGA !!!
// Funkcja insert powinna być zaimplementowana tylko JEDEN
// raz. Wszystkie obiekty z listy powinny zostać usunięte gdy lista
// zostanie usunięta.

// Prosze zwrocic uwage na zarzadzanie pamiecia. Tak aby nie bylo
// wyciekow, ani podwojnego usuwania obiektow.

// Klasy TabInt i TabChar, powinny obsługiwać dowolne rozmiary tablic.

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Lab09. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). Powinien działać dla dowolnej
// liczby przekształceń.

// Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
// ani żadnych innych materiałów (w tym własnych wcześniej
// przygotowanych plików)

// Kody źródłowe muszą znajdować się w katalogu ~/oop/lab_LABNR. Prawa
// do tego katalogu muszą być równe 700 (tylko dostęp dla
// właściciela).

// Skonczone zadanie nalezy wyslac uruchamiajac skrypt 
// /home/dokt/dog/WyslijZadanie.sh
// bedac w katalogu zawierajacym rozwiazanie czyli ~/oop/lab_09

#include"lab09.h"

int main ()
{
  TabInt* wt_calkowite = new TabInt ("liczby", 2);
  wt_calkowite->Set(0, 10);	// ustaw wartosc pierwszego elementu tablicy
  wt_calkowite->Set(1, 20);	// ustaw wartosc drugiego elementu tablicy

  TabChar* wt_znaki = new TabChar ("znaki", 3);
  wt_znaki->Set(0, 'p');	// ustaw wartosc pierwszego elementu tablicy
  wt_znaki->Set(1, 'i');	// ustaw wartosc drugiego elementu tablicy
  wt_znaki->Set(2, 'q');	// ustaw wartosc trzeciego elementu tablicy

  TabIntChar* wt_calkowiteZnaki = new TabIntChar ("liczby i znaki", 2, 2);
  wt_calkowiteZnaki->SetChar(0, 'a');	// ustaw wartosc pierwszego elementu tablicy znakow
  wt_calkowiteZnaki->SetChar(1, 'b');	// ustaw wartosc drugiego elementu tablicy znakow
  wt_calkowiteZnaki->SetInt(0, 1);	// ustaw wartosc pierwszego elementu tablicy liczb
  wt_calkowiteZnaki->SetInt(1, 2);	// ustaw wartosc drugiego elementu tablicy liczb

  List all;
  all.insert(*wt_calkowite);
  all.insert(*wt_znaki);
  all.insert(*wt_calkowiteZnaki);
  
  all.PrintAll();
}
/*
liczby:
(10, 20)
znaki:
(p, i, q)
liczby i znaki:
(a, b)
(1, 2)
*/
