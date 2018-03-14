#include "Macierz.h"
#include <iostream>
#include "WektorTransponowany3D.h"


Macierz::Macierz(const double arr[][3], const int rows)
{
	m_rows = rows;
	m_array = new double * [rows];

	for(int i = 0; i < rows; ++i)
	{
		m_array[i] = new double [3];

		for(int j = 0; j < 3; ++j)
		{
			m_array[i][j] = arr[i][j];
		}
	}
}

Macierz::~Macierz()
{
	for(int i = 0; i < m_rows; ++i)
	{
		delete [] m_array[i];
	}

	delete [] m_array;
}

void Macierz::Wypisz() const
{
	for(int i = 0; i < m_rows; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			std::cout << m_array[i][j];

			if(j % 3 != 2)
				std::cout << "\t";
			else
				std::cout << std::endl;
		}
	}
}

Macierz & Macierz::operator=(const Macierz & macierz)
{
	if(this == &macierz)
		return *this;

	//////////////////////////////////
	for(int i = 0; i < m_rows; ++i)
	{
		delete [] m_array[i];
	}

	delete [] m_array;
	//////////////////////////////////

	m_rows = macierz.m_rows;
	m_array = new double * [m_rows];

	for(int i = 0; i < m_rows; ++i)
	{
		m_array[i] = new double [3];

		for(int j = 0; j < 3; ++j)
		{
			m_array[i][j] = macierz.m_array[i][j];
		}
	}

	return *this;
}

WektorTransponowany3D Macierz::operator()(const int indeks) const 
{
	if(indeks < m_rows)
		return WektorTransponowany3D(m_array[indeks][0], m_array[indeks][1], m_array[indeks][2]);
	else 
		return WektorTransponowany3D(0, 0, 0);
}

double Macierz::operator()(const int row, const int column) const
{
	if(row < m_rows && column < 3)
		return m_array[row][column];
	else 
		return -1;
}

