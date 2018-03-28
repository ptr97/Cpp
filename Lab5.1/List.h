#ifndef __LIST_H__
#define __LIST_H__

#include "Data.h"


struct Node
{
	DataBase * m_data;
	Node * m_next;
};


class List 
{
public:
	enum
	{
		Begin = 0,
		End = 1
	};

	List();
	List(const List & oldList);
	~List();
	List & operator=(const List & list);
	List & insert(const DataBase & data, int insertPlace = 1);
	void print() const;
	bool find(const DataBase & data) const;

private:
	Node * m_first;
};

List::List() : m_first(NULL)
{

}

List::~List()
{
	while(m_first->m_next)
	{
		Node * iter = m_first;
		Node * lastNode = m_first;

		while(iter->m_next)
		{
			lastNode = iter;
			iter = iter->m_next;

		}

		delete iter->m_data;
		delete iter;
		lastNode->m_next = NULL;
	}

	delete m_first->m_data;
	delete m_first;
}

List::List(const List & oldList) : m_first(NULL)
{
	Node * oldListIter = oldList.m_first;
	Node * iter;

	while(oldListIter)
	{
		Node * newNode = new Node;
		newNode->m_next = NULL;
		newNode->m_data = oldListIter->m_data->copy();

		if(!m_first)
		{
			m_first = newNode;
			iter = m_first;
		}
		else
		{
			iter->m_next = newNode;
			iter = iter->m_next;
		}

		oldListIter = oldListIter->m_next;
	}
}

List & List::insert(const DataBase & data, int insertPlace)
{
	Node * newNode = new Node;
	newNode->m_next = NULL;
	newNode->m_data = data.copy();

	if(insertPlace == End)
	{
		if(!m_first)
		{
			m_first = newNode;
		}
		else
		{
			Node * iter = m_first;

			while(iter->m_next)
			{
				iter = iter->m_next;
			}
			iter->m_next = newNode;
		}

	}
	else
	{
		newNode->m_next = m_first;
		m_first = newNode;
	}

	return *this;
}

void List::print() const
{
	std::cout << "[ ";

	Node * iter = m_first;

	while(iter)
	{
		iter->m_data->print();
		iter = iter->m_next;
	}

	std::cout << "]" << std::endl;
}

bool List::find(const DataBase & data) const
{
	bool ifFound = false;
	Node * iter = m_first;

	while(iter)
	{
		if(iter->m_data->equal(&data))
			ifFound = true;
		
		iter = iter->m_next;
	}

	return ifFound;
}

#endif
