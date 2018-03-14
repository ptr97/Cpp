// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Nalezy zaimplementowac klase dzialajaca dzialajaca podobnie do
// std::unique_ptr. Gdy obiekt tej klasy jest niszczony rowniez obiekt
// na ktory wskazuje jest niszczony.

// Prosze zadbac, aby nie bylo wyciekow pamieci, ani wielokrotnego
// zwalniania tego samego obszaru. Do testow polecam valgrinda.

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Lab06. Program nalezy kompilowac z flagami -Wall -g.

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
// bedac w katalogu zawierajacym rozwiazanie czyli ~/oop/lab_06

#include"lab06.h"
#include<iostream>

int main ()
{
  {
    Num_ptr number1 = Number::NumFactory (1.22); // Creating number: 1
    number1->Print();			      // This is number: 1
  }					      // Destroying number: 1
  
  Num_ptr number2 = Number::NumFactory (2); // Creating number: 2
  number2 = Number::NumFactory (3);	    // Creating number: 3
                                            // Destroying number: 2
  
  Num_ptr number4 = Number::NumFactory (4); // Creating number: 4
  number2 = number4;			    // Destroying number: 3
  number2 = number2;

  number2->Print();		// This is inumber: 4
  number2.Delete();		// Destroying number: 4

  Num_ptr number5 = Number::NumFactory (5); // Creating number: 5
  {
    Num_ptr number6 = number5;
  }                             // Destroying number: 5
  
  std::cout<<"END"<<std::endl;	// END
  
  return 0;
}

/*
Creating number: 1
This is number 1
Destroying number: 1
Creating number: 2
Creating number: 3
Destroying number: 2
Creating number: 4
Destroying number: 3
This is number 4
Destroying number: 4
Creating number: 5
Destroying number: 5
END
*/
