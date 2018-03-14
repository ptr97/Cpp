#include "MaszynaStanow.h"

MaszynaStanow::MaszynaStanow()
{
	m_licznik = 0;
	m_stan = 0;
	m_tab = NULL;
}

void MaszynaStanow::start()
{
	m_stan = 0;
}

void MaszynaStanow::operator+=(Stan * stan)
{
	++m_licznik;
	
	if(!m_tab)
	{
		m_tab = new Stan * [m_licznik];
		m_tab[0] = stan;
	}
	else
	{
		Stan ** temp = m_tab;
		m_tab = new Stan * [m_licznik];
		for(int i = 0; i < m_licznik - 1; ++i)
		{
			m_tab[i] = temp[i];
		}

		m_tab[m_licznik - 1] = stan;

		delete [] temp;
	}
}

MaszynaStanow & MaszynaStanow::operator()()
{
	std::cout << "Wykonanie w stanie: ";
	m_tab[m_stan]->Print();
	std::cout << std::endl;
	return *this;
}

void MaszynaStanow::operator++()
{
	m_stan = (m_stan + 1) % m_licznik;
}

void MaszynaStanow::operator--()
{
	--m_stan;
}

MaszynaStanow::~MaszynaStanow()
{
	for(int i = 0; i < m_licznik; ++i)
		delete m_tab[i];
	delete [] m_tab;
}

std::ostream & operator<<(std::ostream & os, const MaszynaStanow & ms)
{
	for(int i = 0; i < ms.m_licznik; ++i)
	{
		os << i << " ";
		ms.m_tab[i]->Print();
		
		if(i == ms.m_stan)
			os << " < ";
		
		os << std::endl;
	}

	return os;
}
