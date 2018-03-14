#pragma once
#include "Tab.h"


struct Node
{
	Node * next;
	Tab * element;
};

class List
{
public:
	List();
	void insert(Tab & tab);
	void PrintAll() const;
	~List();

private:
	Node * m_first;
};


List::List()
{
	m_first = NULL;
}

void List::insert(Tab & tab)
{
	Node * newNode = new Node;

	newNode->next = NULL;
	newNode->element = &tab;

	if(!m_first)
		m_first = newNode;
	else
	{
		Node * iter = m_first;

		while(iter->next)
			iter = iter->next;

		iter->next = newNode;
	}
}

void List::PrintAll() const
{
	Node * iter = m_first;

	while(iter)
	{
		iter->element->Print();
		iter = iter->next;
	}
}

List::~List()
{
	while(m_first)
	{
		Node * temp = m_first->next;
		
		delete m_first->element;
		delete m_first;

		m_first = temp;
	}
}

