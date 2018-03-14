#pragma once
#include <iostream>

#include "Vector.h"
#include "VectorTrans.h"

class VectorTrans;
class Vector;

class Matrix
{
public:
	Matrix(int *** matrix, const int size);
	~Matrix();
	
	friend std::ostream & operator<<(std::ostream & os, const Matrix & matrix);


private:
	int ** m_matrix;
	int m_size;
};

