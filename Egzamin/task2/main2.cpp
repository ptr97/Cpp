#include "fifo.h"

namespace std { class queue{}; }


int main()
{
	fifo<> f;

	for(int i: {1, 2, 3, 4, 5, 6, 7, 8, 9, 0})
		f.push(i);

	fifo<int, std::deque> fp = f;

	std::cout << "Pierwszy element: " << fp.get() << std::endl;
	std::cout << "Rozmiar: " << fp.size() << std::endl;

	for(fifo<>::storage_type::const_iterator it = fp.begin(); it != fp.end(); ++it)
		std::cout << *it << ",";
}
/* Output:
fifo<T, StorageType>::fifo() [with T = int; StorageType = std::deque]
Pierwszy element: 1
Rozmiar: 9
2,3,4,5,6,7,8,9,0,
*/
