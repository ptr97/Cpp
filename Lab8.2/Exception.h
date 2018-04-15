#pragma once

#include "ObjArray.h"

class ObjArrayException
{
public:
	ObjArrayException(ObjArray * objArr) : m_objArr(objArr) {}
	~ObjArrayException() {delete m_objArr;}

private:
	ObjArray * m_objArr;
};
