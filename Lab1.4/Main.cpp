// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Proszę napisać listę, do której będzie można dodawać obiekty
// określonych typów.

// UWAGA !!!
// Funkcja insert powinna być zaimplementowana dwa razy tak, aby można
// było ją wywołać podając jako argument wskaznik lub obiekt. W
// przypadku podaniu wskaznika, obiekt na ktory wskazuje wskaznik
// powinien zostac usuniety wraz z usunieciem listy. W przypadku
// podania obiektu, nie powinien on byc usuwany.

// Prosze zwrocic uwage na zarzadzanie pamiecia. Tak aby nie bylo
// wyciekow, ani podwojnego usuwania obiektow.

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Lab08. Program nalezy kompilowac z flagami -Wall -g.

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
// bedac w katalogu zawierajacym rozwiazanie czyli ~/oop/lab_08

#include"lab08.h"

int main ()
{
  List all;
  all.insert(new Number (3.1));

  Number num1 (31.1);
  all.insert(num1);
  
  IntArray a_int (3);
  a_int[0] = 1;
  a_int[1] = 2.5;
  a_int[2] = 3;

  all.insert(a_int);
  
  FloatArray a_float (3);
  a_float[0] = 1;
  a_float[1] = 2.5;
  a_float[2] = 3;

  all.insert(a_float);
  
  all.PrintAll();
}
/*
Number: 3.1
Number: 31.1
IntArray: (1, 2, 3)
FloatArray: (1, 2.5, 3)
*/
