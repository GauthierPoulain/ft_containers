#include <iostream>

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

int main(void)
{
#ifdef STL
	std::cout << "STL build" << std::endl;
#else
	std::cout << "FT build" << std::endl;
#endif

	return 0;
}
