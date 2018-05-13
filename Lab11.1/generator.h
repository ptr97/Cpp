#pragma once


template <typename Type>
class generator
{
public:
	generator(const Type start, Type (*fun)(Type));
	void operator++();
	bool operator>(const Type val) const;
	bool operator<(const Type val) const;
	Type current() const;
	Type next();
	void reset(const Type val, Type (*fun)(Type));
	void reset();

private:
	Type m_value;
	Type (*m_fun)(Type);
	Type m_initialVal;
};

template <typename Type>
generator<Type>::generator(const Type start, Type (*fun)(Type)) : m_value(start), m_fun(fun), m_initialVal(start)
{

}

template <typename Type>
void generator<Type>::operator++()
{
	m_value = m_fun(m_value);
}

template <typename Type>
bool generator<Type>::operator>(const Type val) const
{
	return m_value > val;
}

template <typename Type>
bool generator<Type>::operator<(const Type val) const
{
	return m_value < val;
}

template <typename Type>
Type generator<Type>::current() const
{
	return m_value;
}

template <typename Type>
Type generator<Type>::next()
{
	m_value = m_fun(m_value);
	return m_value;
}

template <typename Type>
void generator<Type>::reset(const Type val, Type (*fun)(Type))
{
	m_value = val;
	m_fun = fun;
}

template <typename Type>
void generator<Type>::reset()
{
	m_value = m_initialVal;
}

