#pragma once

template <typename T>
class UniquePointer
{
public:
	UniquePointer(T * value) : m_value(value) {}
	~UniquePointer();

	UniquePointer(const UniquePointer &) {}
	UniquePointer(UniquePointer & unqPtr);
	UniquePointer & operator=(UniquePointer & unqPtr);

	const T & operator*() const;
	T & operator*();

	operator T*();

private:
	T * m_value;
};

template <typename T>
UniquePointer<T>::~UniquePointer()
{
	if(m_value)
		delete m_value;
}

template <typename T>
UniquePointer<T>::UniquePointer(UniquePointer & unqPtr)
{
	m_value = unqPtr.m_value;
	unqPtr.m_value = nullptr;
}

template <typename T>
UniquePointer<T> & UniquePointer<T>::operator=(UniquePointer & unqPtr)
{
	if(&unqPtr == this)
		return *this;
	
	if(m_value)
		delete m_value;

	m_value = unqPtr.m_value;
	unqPtr.m_value = nullptr;

	return *this;
}

template <typename T>
const T & UniquePointer<T>::operator*() const
{
	return *m_value;
}

template <typename T>
T & UniquePointer<T>::operator*()
{
	return *m_value;
} 

template <typename T>
UniquePointer<T>::operator T*()
{
	return &*m_value;
}
