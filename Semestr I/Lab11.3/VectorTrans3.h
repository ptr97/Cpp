#pragma once 
#include <iostream>


class Vector3;
class number_t;

class VectorTrans3
{
public:
	VectorTrans3(double x = 0, double y = 0, double z = 0);
	friend std::ostream & operator<<(std::ostream & os, const VectorTrans3 & vector);
	number_t operator*(const Vector3 & vector) const;
	double Get(const int index) const { return m_arr[index]; };

private:
	double m_arr[3];
};

