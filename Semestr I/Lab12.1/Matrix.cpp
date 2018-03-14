#include "Matrix.h"


Matrix::Matrix(int *** matrix, const int size)
{
	m_matrix = *matrix;
	m_size = size;
}

Matrix::~Matrix()
{
	for(int i = 0; i < m_size; ++i)
		delete [] m_matrix[i];

	delete [] m_matrix;
}

std::ostream & operator<<(std::ostream & os, const Matrix & matrix)
{
	for(int j = 0; j < matrix.m_size; ++j)
	{
		os << "[";

		for(int i = 0; i < matrix.m_size; ++i)
		{
			os << matrix.m_matrix[i][j];

			if(i % matrix.m_size != matrix.m_size - 1)
				os << ", ";
		}
		os << "]" << std::endl;
	}

	return os;	
}
