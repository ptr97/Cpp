#include "task1.h"


int main()
{
	Derived1 d1;
	Derived3 d3;
	Derived2 d2 = d3;
	// Derived1 d = d2;   //error

	std::vector<Base *> v = {&d1, &d2, &d3};

	// std::vector<Base> v= {d1, d2, d3};  //error

	std::cout << *v.front();
	std::cout << v;

	return 0;
}
/* Output:
virtual std::ostream& Derived1::print(std::ostream&) const
[
virtual std::ostream& Derived1::print(std::ostream&) const
virtual std::ostream& Derived2::print(std::ostream&) const
virtual std::ostream& Derived3::print(std::ostream&) const
]
*/

