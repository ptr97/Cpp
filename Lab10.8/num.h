#pragma once


namespace num
{

template <typename Type>
double srednia(const Type * tab, const int rozmiar)
{
	double suma = 0;

	for(int i = 0; i < rozmiar; ++i)
		suma += static_cast<double>(tab[i]);

	return (suma / rozmiar);
}

template <typename Type, int rozmiar>
double srednia(const Type (&tab)[rozmiar])
{
	double suma = 0;

	for(int i = 0; i < rozmiar; ++i)
		suma += static_cast<double>(tab[i]);

	return (suma / rozmiar);
}

bool Pierwsza(const int liczba)
{
	bool czyPierwsza = true;

	for(int i = 2; i < liczba; ++i)
	{
		if(liczba % i == 0)
		{
			czyPierwsza = false;
			break;
		}
	}

	return czyPierwsza;
}

template <int start, int koniec, int rozmiar>
bool czyWszystkiePierwszwe(const int (&tab)[rozmiar])
{
	bool czyPierwsze = true;

	for(int i = start; i < koniec; ++i)
	{
		if(!Pierwsza(tab[i]))
		{
			czyPierwsze = false;
			break;
		}
	}

	return czyPierwsze;
}

const char * text(const bool boolean)
{
	if(boolean)
		return "TRUE";
	return "FALSE";
}

}
