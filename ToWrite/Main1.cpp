// Nazwa pliku wykonywalnego: StatkiDwa

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Klasa Statek jest w pelni zaimplemntowana i te implementacje trzeba
// wykorzystac. Klasy Zaglowiec i StatekSilnikowy maja zdefiniowane
// deklaracje, ktorych nie wolno zmieniac i trzeba uzyc. Nalezy
// dopisac implementacje tych klas, a takze zaimplementowac klasy
// Jacht i StatekBaza.

// Prosze zwrocic uwage na zarzadzanie pamiecia.

// Plikow Main.cpp, Statek.h, StatekSilnikowy.h i Zaglowiec.h nie
// wolno modyfikowac.

// Komentarze w kodzie informuja jaki tekst na ekranie wypisuje dana
// linia kodu.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod).

// Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy
// wgrac do UPEL w postaci archiwum spakowanego tarem przy uzyciu polecenia:
// tar czf lab6.tar.gz *

#include<iostream>
#include<string>

#include"Main.h"

int main ()
{
  using namespace std;

  const float masaCalkowitaRejowca = 123;
  Zaglowiec* rejowiec = new Zaglowiec (masaCalkowitaRejowca); // Tworzony jest statek o masie 123.

  const float masaCalkowitaParowcaLekkiego = masaCalkowitaRejowca;
  StatekSilnikowy* parowiecLekki = new StatekSilnikowy (masaCalkowitaParowcaLekkiego); // Tworzony jest statek o masie 123.
  
  const float masaCalkowitaParowcaCiezkiego = 354;
  StatekSilnikowy* parowiecCiezki = new StatekSilnikowy (masaCalkowitaParowcaCiezkiego); // Tworzony jest statek o masie 354.

  rejowiec->ZagleStaw ();
  parowiecLekki->UstawPoziomOleju(0.96);
  parowiecCiezki->UstawPoziomOleju(0.96);

  cout<<"========== RECZNE WYPISANIE ==========\n";
  rejowiec->WypiszStanZagli();	// zagle: postawione
  parowiecLekki->WypiszPoziomOleju(); // Poziom oleju wynosi 0.96.
  parowiecCiezki->WypiszPoziomOleju(); // Poziom oleju wynosi 0.96.


  cout<<"========== WYPISZ INFORMACJE ==========\n";
  rejowiec->WypiszInformacje();	// Masa calkowita tego statku wynosi 123. \n zagle: postawione
  parowiecLekki->WypiszInformacje(); // Masa calkowita tego statku wynosi 123. \n Poziom oleju wynosi 0.96.
  parowiecCiezki->WypiszInformacje(); // Masa calkowita tego statku wynosi 354. \n Poziom oleju wynosi 0.96.


  cout<<"\n";
  cout<<"========== WYPISZ WLASCIWOSCI ==========\n";
  WypiszWlasciwosci (static_cast<const Statek*>(rejowiec)); // To jest zaglowiec. \n zagle: postawione
  WypiszWlasciwosci (static_cast<const Statek*>(parowiecLekki)); // To jest statek silnikowy. \n Poziom oleju wynosi 0.96.
  WypiszWlasciwosci (static_cast<const Statek*>(parowiecCiezki)); // To jest statek silnikowy. \n Poziom oleju wynosi 0.96.

  cout<<"\n";
  cout<<"========== JACHT ==========\n";
  Jacht* darNatury = new Jacht (75); // Tworzony jest statek o masie 75.
  darNatury->ZaglePrecz ();
  darNatury->UstawPoziomOleju (0.34);
  darNatury->Statek::WypiszMaseCalkowita(); // Masa calkowita tego statku wynosi 75.
  darNatury->Zaglowiec::WypiszInformacje(); // Masa calkowita tego statku wynosi 75. \n zagle: zlozone
  darNatury->StatekSilnikowy::WypiszInformacje(); // Masa calkowita tego statku wynosi 75. \n Poziom oleju wynosi 0.34.


  cout<<"========== WLASCIWOSCI JACHTU ==========\n";
  WypiszWlasciwosci (static_cast<Statek*>(darNatury)); // To jest zaglowiec. \n zagle: zlozone \n To jest statek silnikowy. \n Poziom oleju wynosi 0.34.

  Statek* statki [] = {rejowiec, parowiecLekki, parowiecCiezki, darNatury};
  Statek** const koniecStatkow = statki + (sizeof(statki)/sizeof(Statek*));
  for (Statek** lodz = statki; lodz != koniecStatkow; ++lodz)
    delete *lodz;

  return 0;
}
/*
Tworzony jest statek o masie 123.
Tworzony jest statek o masie 123.
Tworzony jest statek o masie 354.
========== RECZNE WYPISANIE ==========
zagle: postawione
Poziom oleju wynosi 0.96.
Poziom oleju wynosi 0.96.
========== WYPISZ INFORMACJE ==========
Masa calkowita tego statku wynosi 123.
zagle: postawione
Masa calkowita tego statku wynosi 123.
Poziom oleju wynosi 0.96.
Masa calkowita tego statku wynosi 354.
Poziom oleju wynosi 0.96.

========== WYPISZ WLASCIWOSCI ==========
To jest zaglowiec.
zagle: postawione
To jest statek silnikowy.
Poziom oleju wynosi 0.96.
To jest statek silnikowy.
Poziom oleju wynosi 0.96.

========== JACHT ==========
Tworzony jest statek o masie 75.
Masa calkowita tego statku wynosi 75.
Masa calkowita tego statku wynosi 75.
zagle: zlozone
Masa calkowita tego statku wynosi 75.
Poziom oleju wynosi 0.34.
========== WLASCIWOSCI JACHTU ==========
To jest zaglowiec.
zagle: zlozone
To jest statek silnikowy.
Poziom oleju wynosi 0.34.
*/
