#include <iostream>
#include <string>

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

void run_benchmark(void)
{
}

void run_test(void)
{
	ft::vector<int> vec1;

	for (size_t i = 0; i < 20; i++)
	{
		vec1.push_back(i);
	}

	ft::vector<int>::iterator iter = vec1.begin();

	vec1.insert(iter + 15, 50);

	while (iter != vec1.end())
	{
		std::cout << *iter++ << std::endl;
	}
}

int main(int argc, char const *argv[])
{
#ifdef STL
	std::cout << "STL build" << std::endl;
#else
	std::cout << "FT build" << std::endl;
#endif
	(void)argc;
	if (argv[1] && std::string(argv[1]) == "test")
		run_test();
	else if (argv[1] && std::string(argv[1]) == "bench")
		run_benchmark();
	else
		std::cout << "usage ./build_name [test|bench (debug)]" << std::endl;
	return 0;
}
