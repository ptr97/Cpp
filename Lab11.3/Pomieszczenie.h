#pragma once

#include <iostream>
#include <string>


class Pomieszczenie
{
public:
	Pomieszczenie(const char * name);
	void zetrzyj_kurze() const;
	void umyj_podloge() const;
	void odkurz() const;
	std::string GetName() const;
	
	template <typename T>
	void wstaw(T t) const;

private:
	std::string m_name;
};

template <typename T>
void Pomieszczenie::wstaw(T t) const
{
	std::cout << "Wstawiam " << t << " do pomieszczenia " << m_name << std::endl;
}
