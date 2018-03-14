#pragma once
#include <iostream>
#include <string>
#include "Wrapper.h"
#include "IntWrapper.h"
#include "FloatWrapper.h"
#include "StringWrapper.h"

struct Node 
{
	Node * m_next;
	Wrapper * m_wrap;
};

class PVec
{
public:
	PVec();
	PVec & push_back(Wrapper * wrPtr);
	friend std::ostream & operator<<(std::ostream & os, const PVec & vec);
	void operator<<(Wrapper * wrPtr);
	Wrapper & operator[](const int index) const;
	Node * First() const;
	~PVec();
private:
	Node * m_first;
};

PVec::PVec()
{
	m_first = NULL;
}

PVec & PVec::push_back(Wrapper * wrPtr)
{
	Node * newNode = new Node;
	newNode->m_next = NULL;
	newNode->m_wrap = wrPtr;

	if(!m_first)
		m_first = newNode;
	else
	{
		Node * iter = m_first;

		while(iter->m_next)
			iter = iter->m_next;

		iter->m_next = newNode;
	}

	return *this;
}

Node * PVec::First() const
{
	return m_first;
}


std::ostream & operator<<(std::ostream & os, const PVec & vec)
{
	Node * iter = vec.First();

		while(iter)
		{
			iter->m_wrap->print(os);
			iter = iter->m_next;
		}

	return os;
}

void PVec::operator<<(Wrapper * wrPtr)
{
	push_back(wrPtr);
}

Wrapper & PVec::operator[](const int index) const 
{
	Node * iter = m_first;

	int place = 0;
	
	while(place != index)
	{
		iter = iter->m_next;
		++place;
	}
	return *(iter->m_wrap);
}

PVec::~PVec()
{
	while(m_first)
	{
		Node * temp = m_first->m_next;

		delete m_first->m_wrap;
		delete m_first;

		m_first = temp;
	}
}
