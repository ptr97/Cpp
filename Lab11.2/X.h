#pragma once

#include <iostream>
#include <string>


class X
{
public:
	X(std::string name = "") : m_name(name) {}
	virtual ~X() {std::cout << "deleting X " << m_name << std::endl;}
	virtual std::string GetName() const {return m_name;}
	friend std::ostream & operator<<(std::ostream & os, const X & x) 
	{
		os << x.GetName();
		return os;
	}

private:
	std::string m_name;
};


class Y : public X
{
public:
	Y(std::string name = "") : X(name) {}
	~Y() override {std::cout << "deleting Y " << this->GetName() << std::endl;}

	friend std::ostream & operator<<(std::ostream & os, const Y & y) 
	{
		os << y.GetName();
		return os;
	}
};
