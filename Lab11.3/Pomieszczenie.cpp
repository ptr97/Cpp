#include "Pomieszczenie.h"


Pomieszczenie::Pomieszczenie(const char * name) : m_name(name)
{
	std::cout << "Tworze pomieszczenie: " << m_name << std::endl;
}

void Pomieszczenie::zetrzyj_kurze() const
{
	std::cout << "Scieram kurze w pomieszczeniu: " << m_name << std::endl;
}

void Pomieszczenie::umyj_podloge() const
{
	std::cout << "Myje podloge w pomieszczeniu: " << m_name << std::endl;
}

void Pomieszczenie::odkurz() const
{
	std::cout << "Odkurzam pomieszczenie: " << m_name << std::endl;
}

std::string Pomieszczenie::GetName() const
{
	return m_name;
}
