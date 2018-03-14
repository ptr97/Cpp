#pragma once

class Grade
{
public:
	Grade(const double value);
	void print() const;



private:
	static int nextID;
	const int m_ID;
	const double m_grade;
};
