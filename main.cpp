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

void vector_test(void);

int main(void)
{

#ifdef STL
	std::cout << "STL build" << std::endl;
#else
	std::cout << "FT build" << std::endl;
#endif

	vector_test();
	return 0;
}
