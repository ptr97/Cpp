#pragma once
#include "Obserwator.h"
#include <vector>

class Obserwowany 
{
public:
	virtual void noweDaneNadeszly(const int dane);
	virtual void dodajObserwatora(Obserwator * nowyObserwator);

private:
	std::vector<Obserwator *> m_obserwatorzy;
};

void Obserwowany::noweDaneNadeszly(const int dane)
{
	for(unsigned int i = 0; i < m_obserwatorzy.size(); ++i)
		m_obserwatorzy[i]->PrzetwarzajDane(dane);
}

void Obserwowany::dodajObserwatora(Obserwator * nowyObserwator)
{
	m_obserwatorzy.push_back(nowyObserwator);
}
