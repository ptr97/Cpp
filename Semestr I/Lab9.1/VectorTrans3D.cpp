#include "VectorTrans3D.h"
#include "Vector3D.h"
#include "Matrix3.h"

#include <iostream>

const int arraySize = 3;


VectorTrans3D::VectorTrans3D(const int first, const int second, const int third)
{
	m_arr[0] = first;
	m_arr[1] = second;
	m_arr[2] = third;

	arrPointer = NULL;
}

void VectorTrans3D::Print() const
{
	for(int i = 0; i < arraySize; ++i)
		std::cout << m_arr[i] << std::endl;
}

Matrix3 VectorTrans3D::Times(const Vector3D & vector3D)
{
	arrPointer = new int * [arraySize];


	for(int i = 0; i < arraySize; ++i)
	{
		arrPointer[i] = new int [arraySize];

		for(int j = 0; j < arraySize; ++j)
		{
			arrPointer[i][j] = m_arr[i] * vector3D.Arr(j);
		}
	}

	return Matrix3(&arrPointer, arraySize);
}

int VectorTrans3D::Arr(const int index) const
{
	return m_arr[index];
}

VectorTrans3D::~VectorTrans3D()
{
	if(arrPointer)
	{
		for(int i = 0; i < arraySize; ++i)
			delete [] arrPointer[i];

		delete [] arrPointer;
	}
}
