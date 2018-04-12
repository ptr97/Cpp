#pragma once
#include <iostream>

class Mebel
{
public:
	Mebel(const int width, const int height, const int length) : m_width(width), m_height(height), m_length(length) {}
	virtual ~Mebel() { std::cout << "~Mebel" << std::endl;}
	friend std::ostream & operator<<(std::ostream & os, const Mebel & mebel)
	{
		mebel.Print(os);
		return os;
	}
	virtual void Print(std::ostream & os) const 
	{
		os << "Mebel: sz:" << m_width << " wys:" << m_height << " dl:" << m_length << " ";
	}
private:
	const int m_width;
	const int m_height;
	const int m_length;
};
