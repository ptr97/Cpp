#pragma once
#include "FitResult.h"


class Fit : public FitResult
{
public:
	virtual void appendPoint(const double x, const double y) {};
	virtual Fit & result() {};
};
