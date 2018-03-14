/* Celem zadania jest napisanie zespolu klas opisujacych 
   "system plikow".
  W takim systemie mozliwe sa dwa typy elementow:
  Dir - katalog, ktory moze zawierac inne elementy wewnatrz (w tym katalogi)
  File - plik, ktory nie moze zawierac innych elementow
  Do obiektu Dir mozna dodac inne elementy.
  Mozna go wypisac (tak jak przykladowy wynik).
  Mozna wyszukac w podkatalogach innego katalogu o zadanej nazwie.
  Na koniec destruktor czysci pamiec
  Pisac mozna 2h15 min.

  UWAGA: W implementacji klasy Dir mozna uzyc dowolnego sposobu 
  na przechowanie podleglych elementow (np. std::list ale statyczna 
  tablica jest tez ok.) Najlepiej wydzielic te czesc z kodu tab by 
  mozna bylo wymienic implementacje w razie potrzeby 
  np. na dynamiczna tablice.

  Kompilowac z flagami -Wall -g do pliku test.
 */

#include <iostream>
#include "FileSystemView.h"


int main() {
  using namespace std;
  Dir *topDir = dir("");
  FileSystemView::print(topDir);
  topDir->append(dir("dev"));
  topDir->append(dir("usr"));

  topDir->append(new Dir("home"));
  Dir* home = topDir->findDir("home");
  
  home->append(new Dir("me"));
  home->append(new Dir("he"));
  FileSystemView::print(topDir);
    
  topDir->findDir("me")->append(dir("music"));
  topDir->findDir("me")->append(dir("pic"));
  topDir->findDir("me")->append(dir("last"));
  FileSystemView::print(topDir);
    
  Dir* last = topDir->findDir("me")->findDir("last");
  last->append(file("00.jpg"));
  last->append(file("01.jpg"));
  last->append(file("02.jpg"));
  File* index = file("index");
  last->append(index);
  
  topDir->print();
  FileSystemView::print(topDir->findDir("me"));
  FileSystemView::print(index);
  
  delete topDir;  
}
/* wynik
/
----
/
  dev/
  usr/
  home/
    me/
    he/
----
/
  dev/
  usr/
  home/
    me/
      music/
      pic/
      last/
    he/
----
/
  dev/
  usr/
  home/
    me/
      music/
      pic/
      last/
        00.jpg*
        01.jpg*
        02.jpg*
        index*
    he/
----
me/
  music/
  pic/
  last/
    00.jpg*
    01.jpg*
    02.jpg*
    index*
----
index*
----

 */
