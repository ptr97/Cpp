#pragma once
#include <string>
#include <iostream>
#include "UncheckedStausCode.h"
#include "StatusCodeCheckers.h"


class StatusCode
{
public:
	StatusCode() {}
	StatusCode(const int value, bool (*fun)(int), const char * errorName);
	~StatusCode() noexcept(false);

	void operator=(const StatusCode & sCode);

	bool isok() const;
	int status() const;
private:
	int m_value = 0;
	bool m_isOk = true;
	mutable bool m_ifError = false;
	std::string m_name = "default";
};

StatusCode::StatusCode(const int value, bool (*fun)(int), const char * errorName) : m_value(value), m_name(errorName)
{
	m_isOk = fun(m_value);
	m_ifError = true;
}

StatusCode::~StatusCode() noexcept(false)
{
	if(m_ifError)
		throw UncheckedStausCode(m_name);
}

void StatusCode::operator=(const StatusCode & sCode)
{
	m_value = sCode.m_value;
	m_isOk = sCode.m_isOk;
	m_ifError = sCode.m_ifError;
	m_name = sCode.m_name;
	sCode.isok();
}

bool StatusCode::isok() const 
{
	m_ifError = false;
	return m_isOk;
}

int StatusCode::status() const
{
	return m_value;
}
