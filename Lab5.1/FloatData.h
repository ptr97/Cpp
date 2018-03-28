#ifndef __FLOATDATA_H__
#define __FLOATDATA_H__

#include <iostream>
#include "DataBase.h"


class FloatData : public DataBase
{
public:
	FloatData(const float value) : m_value(value) {}
	virtual void print() const override;
	virtual bool equal(const DataBase * data) const override;
	virtual FloatData * copy() const override;
	virtual ~FloatData() override;

private:
	const float m_value;

};


void FloatData::print() const 
{
	std::cout << " " << m_value;
}

bool FloatData::equal(const DataBase * data) const 
{
	bool ifEqual = false;

	if(const FloatData * floatData = dynamic_cast<const FloatData *>(data))
	{
		if(floatData->m_value == m_value)
			ifEqual = true;
	}

	return ifEqual;
}

FloatData * FloatData::copy() const 
{
	FloatData * newCopy = new FloatData(m_value);
	return newCopy;
}

FloatData::~FloatData() 
{
	std::cout << "~FloatData()" << std::endl;
}

#endif
