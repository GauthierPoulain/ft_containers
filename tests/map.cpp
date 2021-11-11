#include <string>
#include <iostream>

#ifdef STL
#include <map>
namespace ft = std;
#else
#include "../includes/map.hpp"
#endif

template <typename T1, typename T2>
void print_map(ft::map<T1, T2> map)
{
	for (typename ft::map<T1, T2>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << it->first << " [" << it->second << "] ";
	std::cout << std::endl;
}
template <typename T1, typename T2, typename T3>
void print_map(ft::map<T1, ft::pair<T2, T3> > map)
{
	for (typename ft::map<T1, T2>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << it->first << " [" << it->second.first << ", " << it->second.second << "]";
	std::cout << std::endl;
}

void map_test()
{
	// if (false)
	{
		ft::map<char, int> test;
		test['a'] = 10;
		test['b'] = 30;
		test['d'] = 70;
		ft::map<char, int> test2(test.begin(), test.end());
		ft::map<char, int> test3(test2);
		test3.insert(ft::make_pair('c', 15));
		test3.insert(ft::make_pair('j', 150));
		test3['d'] = 100;
		ft::map<char, int> test4 = test3;
		test['b'] = 40;
		test3['d'] = 90;
		print_map(test);
		print_map(test2);
		print_map(test3);
		print_map(test4);
	}
	// if (false)
	{
	}
}
