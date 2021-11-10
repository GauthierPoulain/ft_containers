#include <string>
#include <iostream>
#include <iomanip>
#include <time.h>

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
void stack_test(void);
void map_test(void);

int main(void)
{

#ifdef STL
	std::cout << "STL build" << std::endl;
#else
	std::cout << "FT build" << std::endl;
#endif

	{
		clock_t start;
		clock_t end;

		start = clock();
		size_t pass = 1;
		for (size_t i = 0; i < pass; i++)
		{
			std::cout << "pass " << i + 1 << '/' << pass << std::endl;
			vector_test();
		}
		end = clock();
		double difference = difftime(end, start);
		std::cout << std::fixed << std::showpoint << std::setprecision(3);
		std::cout << difference / 1000000 << " seconds" << std::endl;
	}

	// stack_test();
	// map_test();
	return 0;
}
