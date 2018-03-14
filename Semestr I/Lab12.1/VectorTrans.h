#pragma once
#include <iostream>

#include "Vector.h"
#include "Matrix.h"

class Vector;
class Matrix;


class VectorTrans
{
public:
	VectorTrans(const int size);
	~VectorTrans();
	int & operator[](const int index);
	int operator[](const int index) const;
	friend std::ostream & operator<<(std::ostream & os, const VectorTrans & vecTrans);
	friend Matrix operator*(const VectorTrans & vecTrans, const Vector & vec);
	friend double operator*(const Vector & vec, const VectorTrans & vecTrans);

private:
	int m_size;
	int * m_arr;
};

