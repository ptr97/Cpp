#pragma once

class ComplexNumber;

class Register
{
public:
	//metoda statyczna czysczaca rejestr
	static void Clear();

	//metoda tworzaca rejestr
	static Register& Retrieve();

	//metoda wyswietlajaca liczbe przechowywana na ekran
	void Print() const;

	//metoda zapisujaca przekazana liczbe zespolona do rejestru
	void Write(ComplexNumber& comNum); 

	//metoda zwracjaca liczbe zespolona przechowywana w rejestrze
	ComplexNumber& Read() const;

	//destruktor zwalniajacy pamiec przydzielona na stercie na rejestr
	~Register();

private:
	//liczba zespolona przechowywana w rejestrze
	static ComplexNumber m_comNum;

	//zmienna informujaca o tym czy rejestr przechowuje obecnie liczbe
	static bool m_ifEmpty;

	//wskaznik do rejestru
	static Register * m_regCopy;
};


