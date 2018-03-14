#pragma once

class Grade;

class GradeBook
{
public:
	GradeBook();
	void insert(const Grade * grade);
	void print() const;
	void addGrade(const int value);
	~GradeBook();

private:
	Grade ** m_array;
	int m_size;
};
