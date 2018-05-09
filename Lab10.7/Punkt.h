#pragma once


class Punkt
{
public:
	Punkt(const int x, const int y) : m_x(x), m_y(y) {}

	template <int i>
	int wsp() const;

	template <typename Type>
	static Type min(const Type arg1, const Type arg2);

	template <typename Type>
	static Type max(const Type arg1, const Type arg2);

	bool operator<(const Punkt & pt) const;

private:
	int m_x;
	int m_y;
};

template <int i>
int Punkt::wsp() const
{
	return 0;
}

template <>
int Punkt::wsp<0>() const
{
	return m_x;
}

template <>
int Punkt::wsp<1>() const
{
	return m_y;
}

template <typename Type>
Type Punkt::min(const Type arg1, const Type arg2)
{
	return (arg1 < arg2) ? arg1 : arg2;
}

template <typename Type>
Type Punkt::max(const Type arg1, const Type arg2)
{
	return (!(arg1 < arg2)) ? arg1 : arg2;
}

bool Punkt::operator<(const Punkt & pt) const
{
	if(m_x == pt.m_x)
		return m_y < pt.m_y;
	return m_x < pt.m_x;
}
