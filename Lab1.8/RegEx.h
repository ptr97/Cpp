#pragma once
#include <string>
#include "Checker.h"
#include "capitalLetter.h"
#include "letter.h"
#include "letterFromRange.h"
#include "anythingUntilLetter.h"

struct Node
{
	const Checker * m_check;
	Node * m_next;
};

class RegEx
{
public:
	RegEx();
	RegEx & operator()(const capitalLetter ch);
	RegEx & operator()(const letter ch);
	RegEx & operator()(const letterFromRange ch);
	RegEx & operator()(const anythingUntilLetter ch);
	RegEx & push(const Checker * ch);
	std::string elements() const;
	bool match(const std::string expression);
	~RegEx();

private:
	Node * m_first;
};


RegEx::RegEx()
{
	m_first = NULL;
}

RegEx & RegEx::operator()(const capitalLetter ch)
{
	Checker * check = new capitalLetter(ch);
	return push(check);
}

RegEx & RegEx::operator()(const letter ch)
{
	Checker * check = new letter(ch);
	return push(check);
}

RegEx & RegEx::operator()(const letterFromRange ch)
{
	Checker * check = new letterFromRange(ch);
	return push(check);
}

RegEx & RegEx::operator()(const anythingUntilLetter ch)
{
	Checker * check = new anythingUntilLetter(ch);
	return push(check);
}


RegEx & RegEx::push(const Checker * ch)
{
	Node * newNode = new Node;
	newNode->m_check = ch;
	newNode->m_next = NULL;

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

std::string RegEx::elements() const
{
	Node * iter = m_first;

	std::string buffer;

	while(iter)
	{
		buffer += iter->m_check->print();
		iter = iter->m_next;
	}

	return buffer;
}

bool RegEx::match(const std::string expression)
{
	Node * iter = m_first;

	int index = 0;
	bool ifMatch = true;

	while(iter)
	{
		if(iter->m_check->match(expression, index))
		{
			iter = iter->m_next;
		}
		else
		{
			ifMatch = false;
			break;
		}
	}
	return ifMatch;
}

RegEx::~RegEx()
{
	while(m_first)
	{
		Node * temp = m_first->m_next;
		delete m_first->m_check;
		delete m_first;
		m_first = temp;
	}
}
