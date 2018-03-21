#pragma once
#include <string>


class CSilnik
{
public:
	CSilnik(const int moc, const int pojemnosc, const char * typ) : m_moc(moc), m_pojemnosc(pojemnosc), m_typ(typ) {}

private:
	const int m_moc;
	const int m_pojemnosc;
	const std::string m_typ;
};
