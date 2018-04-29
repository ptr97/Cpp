// Nazwa pliku wykonywalnego: Mortal

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// UWAGA!
// Wolno korzystac z dokumentacji biblioteki standardowej:
// http://www.sgi.com/tech/stl/table_of_contents.html

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy
// wgrac do UPEL.

#include"Main.h"
#include<set>
#include<list>
#include <vector>
#include<iostream>
#include <cstring>

int main ()
{
  const int studentsNumber = 6;
  char name[20];
  Student array [studentsNumber];
  strcpy (name, "Sub-zero");
  array[0].SetName(name);

  strcpy (name, "Scorpion");
  array[1].SetName(name);

  strcpy (name, "Liu Kang");
  array[2].SetName(name);

  strcpy (name, "Raiden");
  array[3].SetName(name);

  strcpy (name, "Goro");
  array[4].SetName(name);

  strcpy (name, "Agent Lee");
  array[5].SetName(name);

  std::cout<<"----- VECTOR -----\n";
  std::vector<Student> studentsVector (array, array + studentsNumber);
  StudentsClass::PrintStudents(studentsVector);
  std::cout<<"\n";

  std::cout<<"----- NORMAL -----\n";
  std::set<Student> normal;
  normal.insert(array, array + studentsNumber);
  StudentsClass::PrintStudents(normal);
  std::cout<<"\n";

  std::cout<<"----- REVERSE -----\n";
  std::set<Student, ReverseOrder> reverse;
  reverse.insert(array, array + studentsNumber);
  StudentsClass::PrintStudents(reverse);
  std::cout<<"\n";

  std::cout<<"----- LIST -----\n";
  std::list<Student> studentsList = StudentsClass::MakeList(normal);
  studentsList.push_back(array[5]);
  studentsList.push_back(array[0]);
  studentsList.push_front(array[0]);
  StudentsClass::PrintStudents(studentsList);
  std::cout<<"\n";

  std::cout<<"----- SET FROM LIST -----\n";
  std::set<Student> fromList;
  fromList.insert(studentsList.begin(), studentsList.end());
  StudentsClass::PrintStudents(fromList);
    
  return 0;
}
/*
----- VECTOR -----
I am Sub-zero.
I am Scorpion.
I am Liu Kang.
I am Raiden.
I am Goro.
I am Agent Lee.

----- NORMAL -----
I am Agent Lee.
I am Goro.
I am Raiden.
I am Liu Kang.
I am Scorpion.
I am Sub-zero.

----- REVERSE -----
I am Sub-zero.
I am Scorpion.
I am Liu Kang.
I am Raiden.
I am Goro.
I am Agent Lee.

----- LIST -----
I am Sub-zero.
I am Agent Lee.
I am Goro.
I am Raiden.
I am Liu Kang.
I am Scorpion.
I am Sub-zero.
I am Agent Lee.
I am Sub-zero.

----- SET FROM LIST -----
I am Sub-zero.
I am Agent Lee.
I am Sub-zero.
I am Scorpion.
I am Liu Kang.
I am Raiden.
I am Goro.
I am Agent Lee.
I am Sub-zero.
*/
