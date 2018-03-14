// Nazwa pliku wykonywalnego: Loud

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klase TestObj, ktora ma "glosne" (tzn. wypisujace
// tekst) konstruktory i destruktor. Dodatkowo ta klasa ma nazwe.

// UWAGA!!!
// W tym zadaniu nie trzeba kopiowac napisow, dlatego prosze nie uzywac klasy std::string.

// Prosze napisac klase Factory, ktora tworzy obiektu typu TestObj na
// podstawie zadanego wzorca. Jezeli nie zostanie ustawiony zaden
// wzorzec, to tworzone sa obiekty przy uzyciu domyslnego
// konstrutora. Od chwili gdy jest ustawiony jakis wzorzec, tworzone
// sa kopie obiektu wzorcowego.

// Prosze zadbac o dobre zarzadzanie pamiecia.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Loud. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy
// pozostawic w katalogu gdzie byl plik Main.cpp

#include <iostream>
#include "TestObj.h"
#include "Factory.h"

int main() {
  using namespace std;
  { // test funkcjonalnosci kl. TestObj
    delete new TestObj();
    delete new TestObj("text");
    TestObj never("mind");
    delete new TestObj(never);
  }
  std::cout << "Factory\n";
    
  TestObj *test(0); 
  test = Factory::produce();
  cout << "1: " << test->name() << endl;
  test = Factory::produce();
  cout << "2: " << test->name() << endl;
  {
    TestObj newPrototype("better prototype");    
    Factory::prototype(newPrototype);
  }

  test = Factory::produce();
  cout << "3: " << test->name() << endl;
  test = Factory::produce();
  cout << "4: " << test->name() << endl;
  cout << "Clear memory" << std::endl;
  Factory::erase();
}
/* wynik
TestObj::TestObj()
~TestObj(): default
TestObj::TestObj("text")
~TestObj(): text
TestObj::TestObj("mind")
TestObj::TestObj(TestObj("mind"))
~TestObj(): mind
~TestObj(): mind


Factory
TestObj::TestObj()
1: default
TestObj::TestObj()
2: default


TestObj::TestObj("better prototype")
TestObj::TestObj(TestObj("better prototype"))
~TestObj(): better prototype



TestObj::TestObj(TestObj("better prototype"))
3: better prototype
TestObj::TestObj(TestObj("better prototype"))
4: better prototype



Clear memory
~TestObj(): default
~TestObj(): default
~TestObj(): better prototype
~TestObj(): better prototype
~TestObj(): better prototype
*/
