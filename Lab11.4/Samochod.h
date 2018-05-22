#pragma once

#include <iostream>
#include <string>


class Samochod
{
public:
	Samochod() {}
	Samochod(const char * marka, const char * model) 
	: m_marka(marka), m_model(model) {}

	void print() const
	{
		std::cout << m_marka << " " << m_model << std::endl;
	}

private:
	std::string m_marka;
	std::string m_model;
};
