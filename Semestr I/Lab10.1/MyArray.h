#pragma once

class MyArray
{
public:
	//stala referencja do rozmiaru tablicy
	const int& size;

	MyArray(const int arraySize);
	MyArray(const MyArray& myArray);
	int & at(const int index);
	int at(const int index) const;
	void print() const;
	void resize(const int arraySize);
	~MyArray();

private:
	int * m_array;
	int m_size;
};
