#pragma once
#include "Object.h"

class ObjArray
{
public:
	ObjArray(const int size);
	~ObjArray();
	void Set(const int index, Object * obj);
	
private:
	int m_size;
	Object ** m_array;
};
