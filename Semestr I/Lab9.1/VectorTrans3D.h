#pragma once

class Vector3D;

class Matrix3;

class VectorTrans3D
{
public:
	VectorTrans3D(const int first, const int second, const int third);
	void Print() const;
	Matrix3 Times(const Vector3D & vector3D);
	int Arr(const int index) const;
	~VectorTrans3D();

private:
	int m_arr[3];
	int ** arrPointer;
};

