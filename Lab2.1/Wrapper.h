#pragma once


class Wrapper
{
public:
	virtual void print(std::ostream & os) = 0;
	virtual ~Wrapper() {}
};
