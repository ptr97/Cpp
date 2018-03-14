#pragma once

class VectorTrans3D;

class Vector3D
{
public:

	Vector3D(const int first, const int second, const int third);
	void Print() const;
	int Times(const VectorTrans3D & vectorTrans) const;
	int Arr(const int index) const;

private:
	int m_arr[3];
};

