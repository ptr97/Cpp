#pragma once

#include <iostream>
#include <string>

class NazwanyBaza
{
public:
	NazwanyBaza(std::string nazwa) : m_nazwa(nazwa) {}
	virtual void Wypisz() const {std::cout << m_nazwa;}
	virtual ~NazwanyBaza() {}
protected:
	const std::string m_nazwa;
};

