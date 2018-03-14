#include "Fraction.h"
#include <iostream>

Fraction::Fraction(const int numerator, const int denominator)
{
	_whole = numerator / denominator;
	_numerator = numerator % denominator;
	_denominator = denominator;
}

void Fraction::Print() const
{
	if(_whole)
		std::cout << _whole << " ";
	std::cout << _numerator << "/" << _denominator << std::endl;

}

Fraction Fraction::Add(const Fraction frac) const 
{
	int whole = _whole + frac._whole;

	int denominator = _denominator * frac._denominator;
	
	int numerator1 = _numerator * frac._denominator;
	int numerator2 = frac._numerator * _denominator;
	int numerator = numerator1 + numerator2;
	numerator += whole * denominator;

	return Fraction(numerator, denominator);
} 

int Fraction::Numerator() const
{
	return _numerator;
}

int Fraction::Denominator() const 
{
	return _denominator;
}
