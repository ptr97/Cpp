// Do tego pliku mozna dopisac kod, ale niemozna nic zniego usunac
#include "Destroyers.h"
#include "Creators.h"


void DestroyFraction (Fraction* frac)
{
    delete frac;
}

void ClearArray (Fraction *** arr)
{
    int size = SizeOfArray(*arr);

    for(int i = 0; i < size - 1; ++i)
        DestroyFraction( (*arr)[i] );
    delete [] *arr;

    *arr = 0;
}
