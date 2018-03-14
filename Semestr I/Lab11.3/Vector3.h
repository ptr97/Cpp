#pragma once
#include <iostream>

class VectorTrans3;
class Matrix3;
class Hello;

class Vector3
{
public:
	static Hello hey;
	
	Vector3(double x = 0, double y = 0, double z = 0);
	friend std::ostream & operator<<(std::ostream & os, const Vector3 & vector);
	Matrix3 operator*(const VectorTrans3 & vectorTrans) const;
	double Get(const int index) const { return m_arr[index]; };

private:
	double m_arr[3];
};

