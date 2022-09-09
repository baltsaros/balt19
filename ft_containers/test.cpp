#include <iostream>
#include <vector>
#include <exception>
#include "vector.hpp"

// using namespace std;

int	main(void) {

	// testing size vs capacity
	{
		// std::vector<int>	v1 (100, 100);

		// std::cout << "size: " << v1.size() << std::endl;
		// std::cout << "capacity: " << v1.capacity() << std::endl;
	}
	// testing out_of_range
	{
		// std::vector<int>	v1 (4, 100);

		// std::cout << "v1[0]: " << v1[0] << std::endl;
		// std::cout << "v1[3]: " << v1[3] << std::endl;
		// cout << "v1[4]: " << v1.at(4) << endl;
		// if (1 < 2)
		// 	throw out_of_range("range error");
	}

	// ft_vector: access operators
	{
		std::vector<int>	v1 (4, 100);
		ft::vector<int>		v2(4, 100);
		ft::vector<int>		v4;
		int					*p;

		std::cout << "v1.at(0): " << v1.at(0) << std::endl;
		std::cout << "v2.at(0): " << v2.at(0) << std::endl;
		std::cout << "v1.at(3): " << v1.at(3) << std::endl;
		std::cout << "v2.at(3): " << v2.at(3) << std::endl;
		std::cout << "v1.at(2) = 3: " << (v1.at(2) = 3) << std::endl;
		std::cout << "v1.at(2): " << v1.at(2) << std::endl;
		std::cout << "v2.at(2) = 3: " << (v2.at(2) = 3) << std::endl;
		std::cout << "v2.at(2): " << v2.at(2) << std::endl;
		// std::cout << "v1.at(4): " << v1.at(4) << std::endl;
		// std::cout << "v2.at(4): " << v2.at(4) << std::endl;
		std::cout << "v1[0]: " << v1[0] << std::endl;
		std::cout << "v2[0]: " << v2[0] << std::endl;
		std::cout << "v1[2]: " << v1[2] << std::endl;
		std::cout << "v2[2]: " << v2[2] << std::endl;
		// std::cout << "v1[5]: " << v1[5] << std::endl;
		// std::cout << "v2[5]: " << v2[5] << std::endl;
		std::cout << "v1.front(): " << v1.front() << std::endl;
		std::cout << "v2.front(): " << v2.front() << std::endl;
		// std::cout << "EMPTY: v4.front(): " << v4.front() << std::endl;
		std::cout << "v1.at(3) = 6: " << (v1.at(3) = 6) << std::endl;
		std::cout << "v1.at(3): " << v1.at(3) << std::endl;
		std::cout << "v2.at(3) = 6: " << (v2.at(3) = 6) << std::endl;
		std::cout << "v2.at(3): " << v2.at(3) << std::endl;
		std::cout << "v1.back(): " << v1.back() << std::endl;
		std::cout << "v2.back(): " << v2.back() << std::endl;
		std::cout << "p = v1.data(): " << (p = v1.data()) << std::endl;
		std::cout << "p[3]: " << p[3] << std::endl;
		std::cout << "p = v2.data(): " << (p = v2.data()) << std::endl;
		std::cout << "p[3]: " << p[3] << std::endl;
	}
	
	return (0);
}