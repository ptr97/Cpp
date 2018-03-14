#pragma once

class WektorTransponowany3D;

class Macierz
{
public:
	Macierz(const double arr[][3], const int rows);
	~Macierz();
	void Wypisz() const;
	Macierz & operator=(const Macierz & macierz);
	WektorTransponowany3D operator()(const int indeks) const;
	double operator()(const int row, const int column) const;


private:
	double **m_array;
	int m_rows;

};

