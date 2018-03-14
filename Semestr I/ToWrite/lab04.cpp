// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze zaimplementowac klase przechowujaca tablice o dowolnym rozmiarze. 

// UWAGA! Nie wolno korzystac z zadnych juz napisanych klas lub obiektow (w
// tym z biblioteki standardowej) oprocz cout.

// UWAGA! Po zdefiniowaniu w prekompilatorze zmiennej FAIL, program
// nie powinien sie kompilowac. Jezeli program skompiluje sie, oznacza
// to niepoprawna kompilacje i 0 punktow.

// Pliku lab04.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Lab04. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
// ani żadnych innych materiałów (w tym własnych wcześniej
// przygotowanych plików, z wyjatkiem makefile)

// Kody źródłowe muszą znajdować się w katalogu ~/oop/lab_LABNR. Prawa
// do tego katalogu muszą być równe 700 (tylko dostęp dla
// właściciela).

// Skonczone zadanie nalezy wyslac uruchamiajac skrypt 
// ~gach/WyslijZadanie.sh
// bedac w katalogu zawierajacym rozwiazanie czyli ~/oop/lab_04


// #define FAIL

#include"lab04.h"
#include<iostream>

void print_series (array to_be_summed)
{
  // make a series out of the array
  for (int i = 1; i < to_be_summed.size(); ++i)
    to_be_summed.get(i) += to_be_summed.get(i-1);

  to_be_summed.print();
}


int main ()
{
  using namespace std;
  
  float numbers [] = {1, 1, 3, 5, 5};
  int numbersSize = sizeof(numbers)/sizeof(float);

  const array first (numbers, numbersSize);

  cout<<"===== FIRST =====\n";
  first.print();
  cout<<"===== SERIES =====\n";
  print_series(first);
  cout<<"===== FIRST =====\n";
  first.print();
  cout<<"===== EVERY SECOND =====\n";
  cout<<first.get(0);
  for (int i = 2; i < first.size(); i +=2)
    cout<<" "<<first.get(i);
  cout<<"\n";

#ifdef FAIL
  first.get(2) = 1;
#endif
  
  cout<<"========================================\n";
  
  float sum1 = first.squared();	// sum of squared elements
  first.print();
  float sum2 = first.squared().squared(); // sum of elements to the fourth power

  cout<<"sum1: "<<sum1<<"  sum2: "<<sum2<<"\n";

  return 0;
}
/*
===== FIRST =====
1 1 3 5 5
===== SERIES =====
1 2 5 10 15
===== FIRST =====
1 1 3 5 5
===== EVERY SECOND =====
1 3 5
========================================
sum1: 61  sum2: 1333
*/
