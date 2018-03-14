#include "Trojkat.h"


Trojkat::Trojkat(const int a, const int b, const int c)
{
	m_boki[0] = a;
	m_boki[1] = b;
	m_boki[2] = c;
}

void Trojkat::wypisz(std::ostream & os) const
{
	os << "Trojkat o bokach:";

	for(int i = 0; i < 3; ++i)
		os << m_boki[i] << " ";

	std::cout << std::endl;

}

double Trojkat::polePow() const
{
	double polowaObw = 0;

	for(int i = 0; i < 3; ++i)
		polowaObw += m_boki[i];

	polowaObw /= 2;

	return sqrt(polowaObw * (polowaObw - m_boki[0]) * (polowaObw - m_boki[1]) * (polowaObw - m_boki[2]));
}
