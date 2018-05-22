#pragma once

#include "Samochod.h"


class Fabryka
{
public:
	template <typename T>
	void prototyp(T value);

	template <typename T>
	T produkuj() const;

private:
	template <typename T>
	struct Produkt
	{
		static T m_produkt;
	};
};

template <typename T>
T Fabryka::Produkt<T>::m_produkt = T();

template <typename T>
void Fabryka::prototyp(T value)
{
	Produkt<T>::m_produkt = value;
}

template <typename T>
T Fabryka::produkuj() const
{
	return Produkt<T>::m_produkt;
}
