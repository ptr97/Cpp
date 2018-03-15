#include "PVec.h"


PVec & PVec::push_back(Wrapper * wrap)
{
	Node * newNode = new Node;
	newNode->m_next = NULL;
	newNode->m_wrapper = wrap;

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

	return *this;
}

Wrapper & PVec::operator[](const int index) const
{
	Node * iter = m_first;

	for(int i = 0; i < index; ++i)
	{
		iter = iter->m_next;
	}

	return *(iter->m_wrapper);
}

PVec & PVec::operator=(const PVec & vec)
{
	Node * iter = vec.m_first;

	while(iter)
	{
		this->push_back(iter->m_wrapper->Copy());
		iter = iter->m_next;
	}

	return *this;
}

PVec::~PVec()
{
	while(m_first)
	{
		Node * temp = m_first->m_next;

		delete m_first->m_wrapper;
		delete m_first;

		m_first = temp;
	}
}

std::ostream & operator<<(std::ostream & os, const PVec & vec)
{
	Node * iter = vec.m_first;

	while(iter)
	{
		iter->m_wrapper->print(os);
		iter = iter->m_next;
	}
	
	return os;
}
