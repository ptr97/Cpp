#pragma once
#include "Fit.h"


class SlopeFit : public Fit
{
public:
	SlopeFit();
	virtual void appendPoint(const double x, const double y);
	virtual Fit & result();

	virtual char * expression() const;
	virtual unsigned nParams() const;
	virtual char parameterName(const int i) const;
	virtual double parameterValue(const int i) const;

	virtual ~SlopeFit();

private:
	double * m_arr;

};
