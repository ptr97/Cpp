#pragma once

typedef struct fraction
{
	//liczba jednosci
	int whole;
	//licznik ulamka
	int numerator;
	//mianownik ulamka
	int denominator;

}Fraction;

typedef Fraction *** Matrix;



//funkcja inicjalizuje dwuwymiarowa tablice wskaznikow do struktury Fraction
//dynamicznie alokujac pamiec
void InitMatrix (Matrix * matrix, int size);

//funkcja tworzy strukture Fraction - przechowujaca ulamek wlasciwy
void SetFraction (Fraction * frac, int numerator, int denominator);

//funkcja wyswietla ulamek przechowywany w strukturze 
void Print (Fraction * frac);

//funkcja wypelnia macierz liczbami, ktorych licznik ma wartosc danego wiersza,
//a mianownik ma wartosc danej kolumny
void FillRowByColumnPlus1 (Matrix * matrix, int size);

////funkcja wypelnia macierz liczbami, ktorych licznik ma wartosc danego wiersza,
//a mianownik ma wartosc danej kolumny powiekszonej o 5
void FillRowByColumnPlus5 (Matrix * matrix, int size);

//funkcja wyswietla macierz ulamkow
void PrintMatrix (Matrix matrix, int size);

//funkcja sumuje dwie macierze i wyniki zapisuje w macierzy sum
void Sum (Matrix matrix1, Matrix matrix2, int size, Matrix * sum);

//funkcja zwalnia dynamicznie zaalokowana pamiec
void Clear (Matrix matrix, int size);

