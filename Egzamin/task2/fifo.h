#pragma once

#include <iostream>
#include <deque>

template <typename T = int, template <typename U = T, typename Allocator = std::allocator<U>> class StorageType = std::deque>
class fifo
{
public:

	fifo()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

	void push(T & el)
	{
		m_cont.push_back(el);
	}

	T get()
	{
		T temp = m_cont[0];
		m_cont.erase(m_cont.begin());
		return temp;
	}

	int size() const 
	{
		return m_cont.size();
	}

	typedef StorageType<T> storage_type;

	typename storage_type::const_iterator begin() const
	{
		return m_cont.begin(); // std::begin(m_cont);
	}

	typename storage_type::const_iterator end() const
	{
		return m_cont.end(); // std::end(m_cont);
	}

private:
	StorageType<T> m_cont;
};
