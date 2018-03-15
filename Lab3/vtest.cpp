/**
 * Celem zadania jest napisanie plimorficznego wektora. 
 * W wektorze tym trzymac bedziemy wskazniki do obiektow pewnej hierarchii klas.
 * Trudnoscia w zadaniu jest znalezienie hierarchii klas i zapewnienie jej kopiowalnosci.
 * 
 * W ramach powtorki PVec wyposarzony jest w wygodny operator [].
 * 
 * Kompilowac z flagami -Wall -g
 */

#include <iostream>

#include "PVec.h"
#include "PVec.h"


int main() {  
  PVec a;
  PVec b;
  b.push_back(new FloatWrapper(11.2))
    .push_back(new StringWrapper("hello"))
    .push_back(new IntWrapper(-76))
    .push_back(new StringWrapper("world"));
    
  std::cout << b << std::endl;  

  a = b;
  
  std::cout << (const PVec&)a << std::endl;
			 
  std::cout << "\n";
  a[1].print(std::cout);
  a[2].print(std::cout);
  
  std::cout << "\n";
  // UWAGA na potencjalny wyciek pamieci
}
/* wynik
 11.2 hello -76 world
 11.2 hello -76 world

hello-76


*/
