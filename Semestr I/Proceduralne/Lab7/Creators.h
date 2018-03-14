#pragma once

typedef struct fraction
{
    int numerator;
    int denominator;
    int whole;

}Fraction;

//funkcja tworzy strukture Fraction przypisujac do jej pol dane wartosci, od razu wpisuje do struktury ulamek wlasciwy
Fraction* CreateFraction (int numerator, int denominator);

//funckcja wyswietla ulamek na ekran
void Print (Fraction* frac);

//funkcja tworzy strukture tak jak funkcja CreateFraction tylko ze zamiast zwracac wskaznik to modyfikuje otrzymany wskaznik do struktury
void SetFraction (Fraction ** frac, int numerator, int denominator);

//funkcja tworzy nowy ulamek, ktory jest suma dwoch ulamkow
Fraction Sum (Fraction * frac1, Fraction * frac2);

//funkcja tworzy tablice struktur Fraction
Fraction ** CreateArray ();

//funkcja dodaje do tablicy struktur kolejna strukture - frac, alokuje dynamicznei pamiec
void AddToArray (Fraction *** arr, Fraction * frac);

//funkcja tworzy strukture ktora pozniej dodaje do tablicy struktur
void CreateAddToArray (Fraction *** arr, int numerator, int denominator);

//funkcja wyswietla po kolei struktury z tablicy struktur
void PrintArray (Fraction ** arr);

//funkcja zwraca rozmiar tablicy wskaznikow do struktur Fraction
int SizeOfArray(Fraction ** arr);

//funkcja tworzy ulamek z ulamka z czescia calkowita
Fraction* CreateWholeFraction (int whole, int numerator, int denominator);

