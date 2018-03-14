#pragma once
 
class Register;

class ComplexNumber
{
public:
	//konstruktor tworzy obiekt klasy ComplexNumber zaincjalizowany zerami 
	ComplexNumber();

	//konstruktro inicjalizuje składowe klasy podanymi wartościami
	ComplexNumber(const int real, const int imaginary);

	//metoda wyświetlająca ekran obiekt klasy ComplexNumber
	void Print() const;

	//metoda ustawiająca część rzeczywistą liczby zespolonej i zwracająca ten obiekt klasy
	ComplexNumber SetReal(const int real);

	//metoda ustawiająca część urojoną liczby zespolonej i zwracająca ten obiekt klasy
	ComplexNumber SetImaginary(const int imaginary);

	//metoda zapisujaca obiekt do rejestru
	void Save(Register& reg) const;

	//metoda zwracajaca wartosc rzeczywista (getter)
	int Real() const {return m_real;};

	//metoda zwracajaca wartosc zespolona (getter)
	int Imaginary() const {return m_imaginary;};

	//metoda wykonujaca dodawanie dwoch liczn zespolonych i zwracajaca obiekt ktory jest suma dodawania
	ComplexNumber Add(const ComplexNumber& comNum) const;

	//destruktor - tak na prawde tylkko wypisuje jaki obiekt jest automatycznie niszczony
	~ComplexNumber();

private:
	int m_real;
	int m_imaginary;

};

