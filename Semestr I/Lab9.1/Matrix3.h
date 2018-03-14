#pragma once

class Vector3D;
class VectorTrans3D;


class Matrix3
{
public:
	Matrix3(int *** arr3D, const int column);
	void Print() const;
	VectorTrans3D Times(const VectorTrans3D & vectorTrans) const;
	Matrix3 Times(const Matrix3 & matrix);
	int Array3D(const int column, const int row) const;
	~Matrix3();

private:
	int m_arr3D[3][3];
	int ** arrPointer;
};

