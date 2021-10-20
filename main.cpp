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

	return 0;
}
