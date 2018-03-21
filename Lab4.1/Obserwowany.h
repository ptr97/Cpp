#pragma once
#include "Obserwator.h"
#include <vector>

class Obserwowany 
{
public:
	virtual void noweDaneNadeszly(const int dane);
	virtual void dodajObserwatora(ObserwatorBaza * nowyObserwator);

private:
	std::vector<ObserwatorBaza *> m_obserwatorzy;
};

void Obserwowany::noweDaneNadeszly(const int dane)
{
	for(unsigned int i = 0; i < m_obserwatorzy.size(); ++i)
		m_obserwatorzy[i]->PrzetwarzajDane(dane);
}

void Obserwowany::dodajObserwatora(ObserwatorBaza * nowyObserwator)
{
	m_obserwatorzy.push_back(nowyObserwator);
}
