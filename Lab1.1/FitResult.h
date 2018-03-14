#pragma once


class FitResult
{
public:
	virtual char * expression() const {};
	virtual unsigned nParams() const {};
	virtual char parameterName(const int i) const {};
	virtual double parameterValue(const int i) const {};
	virtual ~FitResult() {};
};
