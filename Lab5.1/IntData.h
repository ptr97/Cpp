#ifndef __INTDATA_H__
#define __INTDATA_H__

#include <iostream>
#include "DataBase.h"


class IntData : public DataBase
{
public:
	IntData(const int value) : m_value(value) {}
	virtual void print() const override;
	virtual bool equal(const DataBase * data) const override;
	virtual IntData * copy() const override;
	virtual ~IntData() override;

private:
	const int m_value;

};

void IntData::print() const 
{
	std::cout << " " << m_value;
}

bool IntData::equal(const DataBase * data) const 
{
	bool ifEqual = false;

	if(const IntData * intData = dynamic_cast<const IntData *>(data))
	{
		if(intData->m_value == m_value)
			ifEqual = true;
	}

	return ifEqual;
}

IntData * IntData::copy() const 
{
	IntData * newCopy = new IntData(m_value);
	return newCopy;
}

IntData::~IntData() 
{
	std::cout << "~IntData()" << std::endl;
}

#endif
