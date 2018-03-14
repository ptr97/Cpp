#include "Matrix.h"
#include <iostream>

using namespace std;

void InitMatrix (Matrix * matrix, int size)
{
	*matrix = new Fraction ** [size];
	for(int i = 0; i < size; ++i)
	{
		(*matrix)[i] = new Fraction * [size];

		for(int j = 0; j < size; ++j)
		{
			(*matrix)[i][j] = NULL;
		}
	}
}

void SetFraction (Fraction * frac, int numerator, int denominator)
{
	frac->whole = numerator / denominator;
	frac->numerator = numerator % denominator;
	frac->denominator = denominator;
}

void Print (Fraction * frac)
{
	if(frac->whole)
		cout << frac->whole << " ";
	if(frac->numerator)
		cout << frac->numerator << "/" << frac->denominator;
}

void FillRowByColumnPlus1 (Matrix * matrix, int size)
{
	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			if((*matrix)[i][j])
				delete (*matrix)[i][j];
			(*matrix)[i][j] = new Fraction;
			SetFraction((*matrix)[i][j], i + 1, j + 1);
		}
	}
}

void FillRowByColumnPlus5 (Matrix * matrix, int size)
{
	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			if((*matrix)[i][j])
				delete (*matrix)[i][j];
			(*matrix)[i][j] = new Fraction;
			SetFraction((*matrix)[i][j], i + 1, j + 5);
		}
	}
}

void PrintMatrix (Matrix matrix, int size)
{
	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			Print(matrix[i][j]);
			cout << "\t";
		}
		cout << endl;
	}
}

void Sum (Matrix matrix1, Matrix matrix2, int size, Matrix * sum)
{
	*sum = new Fraction ** [size];

	for(int i = 0; i < size; ++i)
	{
		(*sum)[i] = new Fraction * [size];

		for(int j = 0; j < size; ++j)
		{
			(*sum)[i][j] = new Fraction;

			int whole = matrix1[i][j]->whole + matrix2[i][j]->whole;
			int numerator = matrix1[i][j]->numerator * matrix2[i][j]->denominator + matrix2[i][j]->numerator * matrix1[i][j]->denominator;
			int denominator = matrix1[i][j]->denominator * matrix2[i][j]->denominator;
			numerator += whole * denominator;

			SetFraction((*sum)[i][j], numerator, denominator);
		}
	}
}

void Clear (Matrix matrix, int size)
{
	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			delete matrix[i][j];
		}
		delete [] matrix[i];
	}
	delete [] matrix;
}