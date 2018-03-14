#pragma once 

#include <iostream>


class Matrix3
{
public:
	Matrix3(double arr[][3], const int columns);
	friend std::ostream & operator<<(std::ostream & os, const Matrix3 & matrix);

private:
	double m_arr[3][3];
};

