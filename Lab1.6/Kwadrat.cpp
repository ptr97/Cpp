#include "Kwadrat.h"

Kwadrat::Kwadrat(const int bok) : m_bok(bok)
{

}

void Kwadrat::wypisz(std::ostream & os) const
{
	os << "Kwadrat o boku:" << m_bok << std::endl;
}

double Kwadrat::polePow() const
{
	return m_bok * m_bok;
}
