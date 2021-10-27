#include <iostream>
#include <string>
#include <unistd.h>

#ifdef STL
#include <map>
#include <stack>
#include <vector>
namespace ft = std;
#else
#include "./includes/map.hpp"
#include "./includes/stack.hpp"
#include "./includes/vector.hpp"
#endif

int run_benchmark(bool debug)
{
	std::cout << "running benchmark..." << std::endl;
	(void)debug;
	return 0;
}

int main(int argc, char const *argv[])
{
#ifdef STL
	std::cout << "STL build" << std::endl;
#else
	std::cout << "FT build" << std::endl;
#endif

	if (argc == 2)
	{
		if (std::string(argv[1]) == "bench")
			return run_benchmark(false);
		else if (std::string(argv[1]) == "debug_bench")
			return run_benchmark(true);
	}
	else
	{														 // constructors used in the same order as described above:
		ft::vector<int> first;								 // empty vector of ints
		ft::vector<int> second(4, 100);						 // four ints with value 100
		ft::vector<int> third(second.begin(), second.end()); // iterating through second
		ft::vector<int> fourth(third);						 // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16, 2, 77, 29};
		ft::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

		std::cout << "The contents of fifth are:";
		for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		return 0;
	}

	return 0;
}
