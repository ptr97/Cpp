#pragma once
#include "Element.h"

struct Node
{
	Node * next;
	Element * element;
	bool ifStack;
};

class List
{
public:
	List();
	void insert(Element * el);
	void insert(Element & el);
	void PrintAll() const;
	~List();

private:
	Node * m_first;
};


List::List()
{
	m_first = NULL;
}

void List::insert(Element * el)
{
	Node * newNode = new Node;
	newNode->next = NULL;
	newNode->element = el;
	newNode->ifStack = true;

	if(!m_first)
	{
		m_first = newNode;
	}
	else
	{
		Node * iter = m_first;

		while(iter->next)
		{
			iter = iter->next;
		}

		iter->next = newNode;
	}
}

void List::insert(Element & el)
{
	Node * newNode = new Node;
	newNode->next = NULL;
	newNode->element = &el;
	newNode->ifStack = false;

	if(!m_first)
	{
		m_first = newNode;	
	}
	else
	{
		Node * iter = m_first;

		while(iter->next)
		{
			iter = iter->next;
		}

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
		if(m_first->ifStack)
			delete m_first->element;

		Node * temp = m_first->next;
		delete m_first;
		
		m_first = temp;
	}
}
