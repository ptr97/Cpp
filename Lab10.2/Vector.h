#pragma once


class Vector
{
public:
	template <typename Type>
	static void Initialise(const int size, const Type object = 0);

	template <typename Type>
	static Type & At(const int index);

	template <typename Type>
	static void Reset();

	static int Size() {return m_size;}
	static int m_size;

	template <typename Type>
	struct Array
	{
		static Type * m_items;
	};
};

int Vector::m_size = 0;

template <typename Type>
Type * Vector::Array<Type>::m_items = NULL;


template <typename Type>
void Vector::Initialise(const int size, const Type object)
{
	Vector::m_size = size;
	Vector::Array<Type>::m_items = new Type[Vector::m_size];

	for(int i = 0; i < Vector::m_size; ++i)
	{
		Vector::Array<Type>::m_items[i] = object;
	}
}

template <typename Type>
Type & Vector::At(const int index)
{
	return Vector::Array<Type>::m_items[index];
}

template <typename Type>
void Vector::Reset()
{
	if(Vector::Array<Type>::m_items)
	{
		delete [] Vector::Array<Type>::m_items;
		Vector::Array<Type>::m_items = NULL;
		Vector::m_size = 0;
	}
}
