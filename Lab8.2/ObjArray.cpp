#include "ObjArray.h"
#include "Exception.h"


ObjArray::ObjArray(const int size) : m_size(size)
{
	m_array = new Object * [m_size];

	for(int i = 0; i < m_size; ++i)
		m_array[i] = NULL;
}

ObjArray::~ObjArray()
{
	for(int i = 0; i < m_size; ++i)
		delete m_array[i];

	delete [] m_array;
}

void ObjArray::Set(const int index, Object * obj)
{
	if(index < m_size)
		m_array[index] = obj;
	else
	{
		delete obj;
		throw ObjArrayException(this);
	}
}
