#include "Punkt.h"


bool Punkt::operator<(const Punkt & pt) const
{
	if(m_x == pt.m_x)
		return m_y < pt.m_y;
	else
		return m_x < pt.m_x;
}
