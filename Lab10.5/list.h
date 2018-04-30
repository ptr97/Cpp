#pragma once


namespace agh
{


template <typename T>
class Node
{
public:
	Node(T item) : m_item(item) {}
	Node<T>& operator++();
	T operator*();
	bool operator!=(const Node<T> node);

	Node * m_next = nullptr;
	T m_item;
};

template <typename T>
Node<T>& Node<T>::operator++()
{
	this->m_item = this->m_next->m_item;
	this->m_next = this->m_next->m_next;
	return *this;
}

template <typename T>
T Node<T>::operator*()
{
	return m_item;
}

template <typename T>
bool Node<T>::operator!=(const Node<T> node)
{
	if((*this->m_item) == (*node.m_item))
		std::cout << (*this->m_item) << std::endl;
	return (*this->m_item) != (*node.m_item);
}




template <typename Type>
class list
{
public:
	list() : m_first(nullptr) {}
	~list();
	void push_back(Type item);
	void print() const;
	Node<Type> begin() const;
	Node<Type> end() const;

	using iterator = Node<Type>;

private:
	Node<Type> * m_first;
};

template <typename Type>
list<Type>::~list()
{
	while(m_first)
	{
		Node<Type> * iter = m_first->m_next;
		delete m_first->m_item;
		delete m_first;
		m_first = iter;
	}
}

template <typename Type>
void list<Type>::push_back(Type item)
{
	if(!m_first)
	{
		m_first = new Node<Type>(item);
	}
	else
	{
		Node<Type> * iter = m_first;
		while(iter->m_next)
		{
			iter = iter->m_next;
		}
		iter->m_next = new Node<Type>(item);
	}
}

template <typename Type>
void list<Type>::print() const
{
	Node<Type> * iter = m_first;
	while(iter)
	{
		std::cout << *(iter->m_item);
		if(iter->m_next)
			std::cout << ", ";
		else
			std::cout << std::endl;

		iter = iter->m_next;
	}	
}

template <typename Type>
Node<Type> list<Type>::begin() const
{
	return *m_first;
}

template <typename Type>
Node<Type> list<Type>::end() const
{
	Node<Type> * iter = m_first;
	while(iter->m_next)
	{
		iter = iter->m_next;
	}
	return *iter;
}

}
