// Nazwa pliku wykonywalnego: StudentGrades

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klase Student, ktora reprezentuje studenta. Każdy
// student ma numer ID. Student może mieć oceny.

// Proszę upewnic sie, ze nie ma problemow z pamiecia.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie StudentGrades. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy wgrac
// do UPEL: upel.agh.edu.pl/wfiis/course/view.php?id=22

#include <iostream>
#include "Grade.h"
#include "Student.h"

int main() {
  using std::cout;

  Student denis;
  denis.setID(2);
  denis.print();

  const Grade denisMath (4, denis);
  denis.print();
  
  const Grade denisPhysics (5, denis);
  denis.print();

  denisPhysics.print();

  cout<<"Change Denis ID\n";
  denis.setID(4);
  denis.print();
  denisPhysics.print();

  return 0;
}
/** Wynik dzialania programu:
Student print ID=2
Student print ID=2 grades: 4
Student print ID=2 grades: 4 5
Grade print value=5 studentID=2
Change Denis ID
Student print ID=4 grades: 4 5
Grade print value=5 studentID=4
*/
