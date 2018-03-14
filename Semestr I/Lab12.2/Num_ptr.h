#pragma once

class Number;

class Num_ptr
{
public:
	Num_ptr(Number * ptrNumber);

	Number * operator->();

	Num_ptr & operator=(Number * ptrNumber);

	Num_ptr & operator=(Num_ptr & num_ptr);

	void Delete();

	~Num_ptr();

	Num_ptr(const Num_ptr & num_ptr);

	bool & ref;


private:
	Number * m_ptrNumber;

	bool m_toDelete;

};

