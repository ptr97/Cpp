// Nazwa pliku wykonywalnego: ListaStudentow

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// !!! UWAGA !!! 
// Przy wykonaniu tego zadania nie wolno korzystac z zadnych funkcji i
// obiektow zawartych w bibliotece standardowej (m.in. std::string i
// std::vector) oprocz cout.

// Prosze napisac klase Student reprezentujaca informacje o studencie
// i klase StudentsList reprezentujaca liste/tablice
// studentow. Tablice lub listy powinny dostosowywać swój rozmiar do
// ilości elementów w nich zawartych.

// Prosze zwrocic uwage na dobre zarzadzanie pamiecia, zwlaszcza na
// zwolnienie pamieci na koniec programu.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie ListaStudentow. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile)

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy wgrac
// do UPEL: upel.agh.edu.pl/wfiis/course/view.php?id=22

#include<iostream>
#include "Main.h"

int main ()
{
  StudentsList computerScienceList ("Computer science");
  computerScienceList.PrintInfo();

  computerScienceList.AddStudent(new Student("Rick", "Sanchez"));

  Student* archer = new Student ("Sterling", "Archer");
  archer->Print();
  computerScienceList.AddStudent(archer);
  archer->ParentList()->PrintInfo();

  Student* spiegel = new Student ("Spike", "Spiegel");
  spiegel->Print();
  computerScienceList.AddStudent(spiegel);

  computerScienceList.AddStudent("Duck", "Dodgers");

  std::cout<<"Whole list\n";
  computerScienceList.PrintAll();

  return 0;
}
/* wynik dzialania programu:
Students list: Computer science (address: <adres_listy_studentow>)
Student 2: Sterling, Archer
Students list: Computer science (address: <adres_listy_studentow>)
Student 3: Spike, Spiegel
Whole list
Computer science
Student 1: Rick, Sanchez
Student 2: Sterling, Archer
Student 3: Spike, Spiegel
Student 4: Duck, Dodgers
 */
