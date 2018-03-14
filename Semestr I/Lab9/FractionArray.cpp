#include "FractionArray.h"
#include <iostream>

FractionArray::FractionArray(const int size) : _size(size), _fracCounter(0)
{
	_frac = new Fraction * [size];
	
	for(int i = 0; i < _size; ++i)
		_frac[i] = NULL;

	//_fracCounter = 0;
}

void FractionArray::Print() const
{
	for(int i = 0; i < _size; ++i)
	{
		std::cout << i << ": ";
		_frac[i]->Fraction::Print(); 
	}
}

void FractionArray::AddFration(const int numerator, const int denominator)
{
	_frac[_fracCounter] = new Fraction(numerator, denominator);
	++_fracCounter;
}

Fraction FractionArray::Sum() const
{
	int denominator = 1;

	for(int i = 0; i < _size; ++i)
	{
		denominator *= _frac[i]->Denominator();
	}

	int * numerators = new int [_size];

	for(int i = 0; i < _size; ++i)
	{
		numerators[i] = _frac[i]->Numerator() * denominator / _frac[i]->Denominator();
	}


	int numerator = 0;

	for(int i = 0; i < _size; ++i)
		numerator += numerators[i];

	delete [] numerators;

	return Fraction(numerator, denominator);

}

FractionArray::~FractionArray()
{
	for(int i = 0; i < _size; ++i)
	{
		delete _frac[i];
	}

	delete [] _frac;
}
