#include "Vector3D.h"
#include "VectorTrans3D.h"

#include <iostream>

const int arraySize = 3;

Vector3D::Vector3D(const int first, const int second, const int third)
{
	m_arr[0] = first;
	m_arr[1] = second;
	m_arr[2] = third;
}

void Vector3D::Print() const
{
	std::cout << "(";

	for(int i = 0; i < arraySize; ++i)
	{
		std::cout << m_arr[i];
		if(i % 3 != 2)
			std::cout << ", ";
	}
	
	std::cout << ")" << std::endl;
}

int Vector3D::Times(const VectorTrans3D & vectorTrans) const
{
	int sum = 0;

	for(int i = 0; i < arraySize; ++i)
	{
		sum += m_arr[i] * vectorTrans.Arr(i);
	}

	return sum;
}

int Vector3D::Arr(const int index) const
{
	return m_arr[index];
}



