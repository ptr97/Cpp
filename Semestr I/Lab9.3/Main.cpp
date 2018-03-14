// Nazwa pliku wykonywalnego: Simple

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klase ComplexNumber, ktora reprezentuje liczbe
// zespolona. Prosze zwrocic uwage, ze nie da sie stworzyc obiektu tej
// klasy nie podajac zadnych wartosci liczbowych.

// Prosze napisac klase ComplexArray, ktora bedzie tablica liczb
// zespolonych.

// UWAGA!!!
// Po uruchomieniu linii ERROR, powinien pojawic sie blad kommpilacji
// dokladnie w tej linii. Brak bledu oznacza -2 punkty.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Simple. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy
// pozostawic w katalogu gdzie byl plik Main.cpp

#include"ComplexNumber.h"
#include"ComplexArray.h"

// #define ERROR

int main ()
{
  ComplexNumber firstNumber (3, 2);

  firstNumber.Print();
  const ComplexNumber secondNumber (firstNumber);
  firstNumber.Print();

  firstNumber = 4;
  firstNumber.Print();


#ifdef ERROR
  ComplexNumber errorNumber;
#endif
  
  const int arraySize = 3;
  ComplexArray array (arraySize);
  array.At(0) = firstNumber;
  array.Set(1, ComplexNumber(1, 2));
  array.At(2) = firstNumber.Add(secondNumber);
  array.Print();

  array.At(1) = 5;

  array.Print();
  
  return 0;
}
/*
3 + 2i
3 + 2i
4 + 0i
Array:
1: 4 + 0i
2: 1 + 2i
3: 7 + 2i
Array:
1: 4 + 0i
2: 5 + 0i
3: 7 + 2i
*/
