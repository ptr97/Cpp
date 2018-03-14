#include "Kolo.h"


Kolo::Kolo(const int promien) : m_promien(promien)
{

}

void Kolo::wypisz(std::ostream & os) const
{
	os << "Kolo o promieniu:" << m_promien << std::endl;
}

double Kolo::polePow() const
{
	return M_PI * m_promien * m_promien;
}
