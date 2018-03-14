// Do tego pliku mozna dopisac kod, ale niemozna nic zniego usunac
#include "Creators.h"
#include "Destroyers.h"
#include <iostream>

using namespace std;

Fraction* CreateFraction (int numerator, int denominator)
{
    Fraction * frac = new Fraction;

    frac->whole = numerator / denominator;
    frac->numerator = numerator % denominator;
    frac->denominator = denominator;

    return frac;
}

void Print (Fraction* frac)
{
    if(frac->whole)
        cout << frac->whole << " ";
    cout << frac->numerator << "/" << frac->denominator << endl;
}

void SetFraction (Fraction ** frac, int numerator, int denominator)
{
    *frac = new Fraction;

    (*frac)->whole = numerator / denominator;
    (*frac)->numerator = numerator % denominator;
    (*frac)->denominator = denominator;
}

Fraction Sum (Fraction * frac1, Fraction * frac2)
{
    Fraction frac;
    frac.whole = frac1->whole + frac2->whole;

    int numerator, denominator;

    denominator = frac1->denominator * frac2->denominator;
    int numerator1 = frac1->numerator * frac2->denominator;
    int numerator2 = frac2->numerator * frac1->denominator;

    numerator = numerator1 + numerator2;

    if(numerator / denominator)
    {
        frac.whole += numerator / denominator;
        frac.numerator = numerator % denominator;
    }
    else
    {
        frac.whole += 0;
        frac.numerator = numerator;
    }

    frac.denominator = denominator;

    return frac;
}

Fraction ** CreateArray ()
{
    Fraction ** arr = new Fraction *[1];
    *arr = NULL;

    return arr;
}

void AddToArray (Fraction *** arr, Fraction * frac)
{
    int size = SizeOfArray(*arr);
    Fraction ** oldArr = *arr;

    *arr = new Fraction * [size + 1];

    for(int i = 0; i < size - 1; ++i)
    {
        (*arr)[i] = CreateWholeFraction(oldArr[i]->whole, oldArr[i]->numerator, oldArr[i]->denominator);
    }

    ClearArray(&oldArr);

    (*arr)[size - 1] = CreateWholeFraction(frac->whole, frac->numerator, frac->denominator);
    (*arr)[size] = NULL;

}

void CreateAddToArray (Fraction *** arr, int numerator, int denominator)
{
    int size = SizeOfArray(*arr);
    Fraction ** oldArr = *arr;

    *arr = new Fraction * [size + 1];

    for(int i = 0; i < size - 1; ++i)
    {
        (*arr)[i] = CreateWholeFraction(oldArr[i]->whole, oldArr[i]->numerator, oldArr[i]->denominator);
    }

    ClearArray(&oldArr);

    (*arr)[size - 1] = CreateFraction(numerator, denominator);
    (*arr)[size] = NULL;
}

void PrintArray (Fraction ** arr)
{
    int size = SizeOfArray(arr);

    if(size)
        cout << "Array size: " << size - 1 << endl;

    for(int i = 0; i < size - 1; ++i)
    {
        cout << i + 1 << ": ";
        Print(arr[i]);
    }
}

int SizeOfArray(Fraction ** arr)
{
    if(!arr)
        return 0;

    int size = 0;
    while(arr[size] != NULL)
        ++size;
    return size + 1;
}

Fraction* CreateWholeFraction (int whole, int numerator, int denominator)
{
    if(whole)
        numerator += whole * denominator;

    return CreateFraction(numerator, denominator);
}