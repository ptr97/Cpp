/*
  Celem zadania jest napisanie programu, ktory zliczy statystyke dotyczaca swojego kodu. 
  Nalezy to zrobic z uzyciem kontenerow standardowych. W szczegilnosci mapy itp.

  Mozna kozystac z dokumentacji biblioteki STL na stronach interenetowych 
  ale nie moga to bys fora z gotowmi odpowiedziami typu StackOverflow itp.
 */
#include <iostream>
#include "Stats.h"

int main(  ) {
  const std::string fname("self.cpp");
  std::cout << "Czytamy plik " << fname << std::endl;

  const Stats wstat = Stats::scanForWords( fname );
  const Stats cstat = Stats::scanForChars( fname );
  std::cout << "Statystyka odczytana: info o slowach\n" ;
  
  std::cout << "slow " << wstat << std::endl; 
  std::cout << wstat.details() << std::endl; 
  std::cout << "Statystyka odczytana: info o znakach\n" ;
  std::cout << "znakow " << cstat << std::endl; 
  std::cout << cstat.details() << std::endl; 

}
