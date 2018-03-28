#ifndef __STRINGDATA_H__
#define __STRINGDATA_H__

#include <string>
#include <iostream>
#include "DataBase.h"


class StringData : public DataBase
{
public:
	StringData(const std::string value) : m_value(value) {}
	virtual void print() const override;
	virtual bool equal(const DataBase * data) const override;
	virtual StringData * copy() const override;
	virtual ~StringData() override;

private:
	const std::string m_value;

};

void StringData::print() const 
{
	std::cout << " " << m_value;
}

bool StringData::equal(const DataBase * data) const 
{
	bool ifEqual = false;

	if(const StringData * stringData = dynamic_cast<const StringData *>(data))
	{
		if(stringData->m_value == m_value)
			ifEqual = true;
	}

	return ifEqual;
}

StringData * StringData::copy() const 
{
	StringData * newCopy = new StringData(m_value);
	return newCopy;
}

StringData::~StringData() 
{
	std::cout << "~StringData()" << std::endl;
}

#endif
