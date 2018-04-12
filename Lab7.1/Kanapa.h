#pragma once
#include "Mebel.h"

class Kanapa : public Sofa, public Lozko
{
public:
	Kanapa(const int width, const int height, const int length, const int seat, const int sleepWidth)
	 : Mebel(width, height, length), Sofa(width, height, length, seat), Lozko(width, height, length, sleepWidth) {}
	~Kanapa() {std::cout << "~Kanapa" << std::endl;}
	friend std::ostream & operator<<(std::ostream & os, const Kanapa & kanapa)
	{
		kanapa.Print(os);
		return os;
	}

	virtual void Print(std::ostream & os) const 
	{
		os << "jako ";
		Mebel::Print(os);
		os << std::endl;

		os << "jako ";
		Sofa::Print(os);
		os << std::endl;
		
		os << "jako ";
		Lozko::Print(os);
	}
};
