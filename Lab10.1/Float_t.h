#pragma once


enum
{
	SECOND = 1,
	METER = 4,
};


template <int ver> 
class Float_t
{
public:
	Float_t(const float value) : m_value(value) {}
	float Get() const {return m_value;}

private:
	float m_value;
};

float operator+(const Float_t<4> fl1, const Float_t<4> fl2)
{
	return fl1.Get() + fl2.Get();
}

float operator/(const Float_t<4> & fl1, const Float_t<1> & fl2)
{
	return fl1.Get() / fl2.Get();
}

float operator/(float value, const Float_t<1> & fl)
{
	return value / fl.Get();
}

float operator+(const Float_t<2> fl1, const Float_t<2> fl2)
{
	return fl1.Get() + fl2.Get();
}
