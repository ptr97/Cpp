#include "Matrix3.h"
#include "Vector3D.h"
#include "VectorTrans3D.h"

#include <iostream>

const int arraySize = 3;

Matrix3::Matrix3(int *** arr3D, const int column)
{
	for(int i = 0; i < arraySize; ++i)
	{
		for(int j = 0; j < column; ++j)
		{
			m_arr3D[i][j] = (*arr3D)[i][j];
		}
	}
	arrPointer = NULL;
}

void Matrix3::Print() const
{
	for(int i = 0; i < arraySize; ++i)
	{
		std::cout << "(";

		for(int j = 0; j < arraySize; ++j)
		{
			std::cout << m_arr3D[i][j];
			if(j % 3 != 2)
				std::cout << ", ";
		}

		std::cout << ")" << std::endl;
	}
}

VectorTrans3D Matrix3::Times(const VectorTrans3D & vectorTrans) const
{
	int sumArray[arraySize] = {0};

	for(int i = 0; i < arraySize; ++i)
	{
		for(int j = 0; j < arraySize; ++j)
		{
			sumArray[i] += m_arr3D[i][j] * vectorTrans.Arr(j);
		}
	}

	return VectorTrans3D(sumArray[0], sumArray[1], sumArray[2]);
}

Matrix3 Matrix3::Times(const Matrix3 & matrix)
{
	arrPointer = new int * [arraySize];


	for(int i = 0; i < arraySize; ++i)
	{
		arrPointer[i] = new int [arraySize];

		for(int j = 0; j < arraySize; ++j)
		{
			arrPointer[i][j] = 0;

			for(int k = 0; k < arraySize; ++k)
			{
				arrPointer[i][j] += m_arr3D[i][k] * matrix.Array3D(k, j);
			}
		}
	}

	return Matrix3(&arrPointer, arraySize);
}

int Matrix3::Array3D(const int column, const int row) const
{
	return m_arr3D[column][row];
}

Matrix3::~Matrix3()
{
	if(arrPointer)
	{
		for(int i = 0; i < arraySize; ++i)
			delete [] arrPointer[i];

		delete [] arrPointer;
	}
}