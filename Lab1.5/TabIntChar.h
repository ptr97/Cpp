#pragma once
#include "TabInt.h"
#include "TabChar.h"


class TabIntChar : public TabInt, public TabChar
{
public:
	TabIntChar(const char * name, const int intSize, const int charSize);
	void SetChar(const int index, const char cValue);
	void SetInt(const int index, const int iValue);
	void PrintName() const;
	void PrintVal() const;
	~TabIntChar();
};

TabIntChar::TabIntChar(const char * name, const int intSize, const int charSize) : Tab(name), TabInt(name, intSize), TabChar(name, charSize)
{

}

void TabIntChar::SetChar(const int index, const char cValue)
{
	TabChar::Set(index, cValue);
}

void TabIntChar::SetInt(const int index, const int iValue)
{
	TabInt::Set(index, iValue);
}

void TabIntChar::PrintName() const
{
	Tab::Print();
}

void TabIntChar::PrintVal() const
{
	TabChar::PrintVal();
	TabInt::PrintVal();
}

TabIntChar::~TabIntChar()
{

}
