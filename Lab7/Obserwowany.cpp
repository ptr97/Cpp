#include "Obserwowany.h"


void Obserwowany::noweDaneNadeszly(const int dane)
{
	for(Obserwator * obs: m_obserwatorzy)
		obs->przetworzDane(dane);
}

void Obserwowany::dodajObserwatora(Obserwator * obserwator)
{
	m_obserwatorzy.push_back(obserwator);
}
