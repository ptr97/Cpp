#pragma once
#include <iostream>
#include <string>
#include <vector>


class Mebel
{
public:
	Mebel(const char * type, const int width, 
		const int height, const int length, const char * description);

	friend std::ostream & operator<<(std::ostream & os, const Mebel & mebel);
	friend std::istream & operator>>(std::istream & is, Mebel & mebel);

private:
	std::string m_type;
	int m_dimensions[3];
	std::string m_description;
};


Mebel::Mebel(const char * type, const int width, 
		const int height, const int length, const char * description)
		: m_type(type), m_description(description)
{
	m_dimensions[0] = width;
	m_dimensions[1] = height;
	m_dimensions[2] = length;
}

std::ostream & operator<<(std::ostream & os, const Mebel & mebel)
{
	os << mebel.m_type << " " << mebel.m_dimensions[0] << " " << mebel.m_dimensions[1] << " ";
	os << mebel.m_dimensions[2] << " \"" << mebel.m_description << "\" ";

	return os;
}

std::istream & operator>>(std::istream & is, Mebel & mebel)
{
	is >> mebel.m_type >> mebel.m_dimensions[0] >> mebel.m_dimensions[1];
	is >> mebel.m_dimensions[2] >> mebel.m_description;

	return is;
}

std::istream & operator>>(std::istream & is, std::vector<Mebel> & vec)
{
	std::string type;
	std::string description;
	int dimensions[3];

	while(is.good())
	{
		is >> type;

		for(int i = 0; i < 3; ++i)
			is >> dimensions[i];

		is.std::istream::ignore(100, '\"');
		std::getline(is, description, '\"');

		if(is.good())
			vec.emplace_back(Mebel(type.c_str(), dimensions[0], dimensions[1], dimensions[2], description.c_str()));
	}

	return is;
}
