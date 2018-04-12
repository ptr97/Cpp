#pragma once
#include "Mebel.h"

class Sofa : virtual public Mebel
{
public:
	Sofa(const int width, const int height, const int length, const int seat) : Mebel(width, height, length), m_seat(seat) {}
	~Sofa() {std::cout << "~Sofa" << std::endl;}
	friend std::ostream & operator<<(std::ostream & os, const Sofa & sofa)
	{
		sofa.Print(os);
		return os;
	}
	virtual void Print(std::ostream & os) const 
	{
		os << "Sofa:";
		Mebel::Print(os);
		os << " siedzisko " << m_seat;	
	}
private:
	int m_seat;
};