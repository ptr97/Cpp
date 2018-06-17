#pragma once
#include <cstring>


template <typename T>
struct is_pod
{
	const static bool value = false;
};

///////////////////////////////////////////////////////

template <typename T>
class Vect
{
public:
	Vect(const unsigned size);
	~Vect();
	const T & operator[](const unsigned index) const {return m_array[index];}
	T & operator[](const unsigned index) {return m_array[index];}
	const unsigned & size() const {return m_size;}

	void buble_sort(bool (*compare)(const T & a, const T & b));

private:
	void swap(T & a, T & b);

	T * m_array;
	unsigned m_size;
};

///////////////////////////////////////////////////////

template <typename U, bool isPod>
struct SwapHelper
{
	static void swap(U & a, U & b) {}
};

template <typename U>
struct SwapHelper<U, false>
{
	static void swap(U & a, U & b)
	{
		U temp = a;
		a = b;
		b = temp;
	}
};

template <typename U>
struct SwapHelper<U, true>
{
	static void swap(U & a, U & b)
	{
		U temp;
		memcpy(&temp, &a, sizeof(U));
		memcpy(&a, &b, sizeof(U));
		memcpy(&b, &temp, sizeof(U));
	}
};

///////////////////////////////////////////////////////

template <typename T>
Vect<T>::Vect(const unsigned size) : m_size(size)
{
	m_array = new T [m_size];
}

template <typename T>
Vect<T>::~Vect()
{
	delete [] m_array;
}

template <typename T>
void Vect<T>::buble_sort(bool (*compare)(const T & a, const T & b))
{
	for(unsigned i = 0; i < m_size; ++i)
	{
		for(unsigned j = i + 1; j < m_size; ++j)
		{
			if(compare(m_array[i], m_array[j]))
				swap(m_array[i], m_array[j]);
		}
	}
}

template <typename T>
void Vect<T>::swap(T & a, T & b)
{
	SwapHelper<T, is_pod<T>::value>::swap(a, b);
}
