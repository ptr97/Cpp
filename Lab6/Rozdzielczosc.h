#pragma once
#include <iostream>


//klasa ktora przedstawia rozdzielczosc urzadzenia, jest skladnikiem urzadzen, przyjmuja ja jej konstruktory 
class Rozdzielczosc
{
public:
	Rozdzielczosc(const int x, const int y) : m_x(x), m_y(y) {}
	
	//przeciazony operator<< sluzacy do wypisywania rozdzielczosci na standardowe wyjscie
	friend std::ostream & operator<<(std::ostream & os, const Rozdzielczosc & roz) 
	{
		os << roz.m_x << "x" << roz.m_y;
		return os;
	}

private:
	int m_x;
	int m_y;
};
