#pragma once


class Number
{
public:
	static Number * NumFactory(const int value);
	void Print() const;
	~Number();

private:
	Number(const int value);

	int m_value;
};

