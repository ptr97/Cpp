#pragma once
#include <iostream>

#include "VectorTrans.h"
#include "Matrix.h"

class VectorTrans;	
class Matrix;

class Vector
{
public:
	Vector(const int size);
	Vector(const Vector & vec);
	~Vector();
	int & operator[](const int index);
	int operator[](const int index) const;
	friend std::ostream & operator<<(std::ostream & os, const Vector & vec);
	friend double operator*(const Vector & vec, const VectorTrans & vecTrans);
	Vector & operator=(const Vector & vec);
	friend Matrix operator*(const VectorTrans & vecTrans, const Vector & vec);

private:
	int m_size;
	int * m_arr;
};

