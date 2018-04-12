#pragma once
#include "Mebel.h"

class Lozko : virtual public Mebel
{
public:
	Lozko(const int width, const int height, const int length, const int sleepWidth) : Mebel(width, height, length), m_sleepWidth(sleepWidth) {}
	~Lozko() {std::cout << "~Lozko" << std::endl;}
	friend std::ostream & operator<<(std::ostream & os, const Lozko & lozko)
	{
		lozko.Print(os);
		return os;
	}
	virtual void Print(std::ostream & os) const 
	{
		os << "Lozko:";
		Mebel::Print(os);
		os << " sz.spania " << m_sleepWidth;
	}
private:
	int m_sleepWidth;
};