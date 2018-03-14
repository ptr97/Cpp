#include "PointCollection.h"
#include "Point3D.h"

#include <iostream>


PointCollection::PointCollection(const int size) : m_size(size)
{
	m_array = new Point3D * [m_size];
}

Point3D *& PointCollection::operator[](const int index)
{
	return m_array[index];
}

void PointCollection::Print() const
{
	for(int i = 0; i < m_size; ++i)
	{
		std::cout << *(m_array[i]) << std::endl;
	}
}

PointCollection::PointCollection(const PointCollection & ptCollect) : m_size(ptCollect.m_size)
{
	m_array = new Point3D * [m_size];

	for(int i = 0; i < m_size; ++i)
	{
		m_array[i] = new Point3D(*(ptCollect.m_array[i]));
	}
}

PointCollection::~PointCollection()
{
	for(int i = 0; i < m_size; ++i)
		delete m_array[i];

	delete [] m_array;
}