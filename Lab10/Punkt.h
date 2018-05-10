#pragma once


// klasa reprezentujaca Punkt na przestrzeni dwuwymiarowej,
// pozwala na porownywanie dwoch punktow
class Punkt
{
public:
	// konstruktor inicjalizujacy obydwie skladowe
	Punkt(int x, int y) : m_x(x), m_y(y) {}

	// przeciazony operator < - porownujacy punlty na plaszczyznie. 
	// Jesli skladowe x sa rowne to porownywane sa skladowe y
	bool operator<(const Punkt & pt) const;

	// funkcja szablonowa zwracajaca wspolrzedna punktu 
	// dla M == 0 zwraca wsp. x, dla M != 0 zwraca wsp. y
	template <int M>
	int wsp() const 
	{
		return M ? m_y : m_x;
	}

	// funkcja szablonowa zwracajaca stala referencje do minimalnego z przekazanych argumentow 
	template <typename Type>
	static const Type & min(const Type & arg1, const Type & arg2)
	{	
		return arg1 < arg2 ? arg1 : arg2;
	}

	// funkcja szablonowa zwracajaca stala referencje do maksymalnego z przekazanych argumentow
	template <typename Type>
	static const Type & max(const Type & arg1, const Type & arg2)
	{
		return arg1 < arg2 ? arg2 : arg1;
	}

private:
	// skladowe prywatne reprezentujace wspolrzedne x oraz y
	int m_x;
	int m_y;
};
