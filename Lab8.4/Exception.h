#pragma once
#include <iostream>


class Exception
{
public:
	virtual int Numer() const
	{
		return 0;
	}

	virtual void PrzedstawSie() const
	{
		std::cout << "Nazywam sie ";
		std::cout << Numer() << std::endl;

	}
	virtual ~Exception() {}
};

class typ3 : public Exception
{
public:
	virtual int Numer() const {return 3;}
};

class typ4 : public Exception
{
public:
	virtual int Numer() const {return 4;}
};

class typ1 : public typ3
{
public:
	virtual int Numer() const {return 1;}
};

class typ2 : public typ4
{
public:
	virtual int Numer() const {return 2;}
};
