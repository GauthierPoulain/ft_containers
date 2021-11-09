#include <string>
#include <iostream>

#ifdef STL
#include <vector>
namespace ft = std;
#else
#include "../includes/vector.hpp"
#endif

template <typename T>
void print_vector(ft::vector<T> vt)
{
	typename ft::vector<T>::iterator it = vt.begin();

	while (it != vt.end())
		std::cout << *it++ << " ";
	std::cout << std::endl;
}

void vector_test()
{
	{
		std::cout << "phase 1" << std::endl;
		ft::vector<char> test;
		for (size_t i = 'a'; i <= 'f'; i++)
			test.push_back(i);
		print_vector(test);
		ft::vector<char> testcpy = ft::vector<char>(test);
		print_vector(testcpy);
		ft::vector<char> testassign = test;
		print_vector(testassign);
		test[2] = 'e';
		print_vector(test);
		print_vector(testcpy);
		print_vector(testassign);
	}
	{
		std::cout << "phase 2" << std::endl;
		ft::vector<char> *test = new ft::vector<char>();
		for (size_t i = 'a'; i <= 'f'; i++)
			test->push_back(i);
		print_vector(*test);
		ft::vector<char> *testcpy = new ft::vector<char>(*test);
		print_vector(*testcpy);
		ft::vector<char> *testassign;
		testassign = test;
		print_vector(*testassign);
		(*test)[2] = 'e';
		print_vector(*test);
		print_vector(*testcpy);
		print_vector(*testassign);
		delete testcpy;
		delete test;
	}
	{
		std::cout << "phase 3" << std::endl;
		ft::vector<char> test;
		for (size_t i = 'a'; i <= 'f'; i++)
			test.push_back(i);
		print_vector(test);
		test.clear();
		print_vector(test);
		for (size_t i = 'a'; i <= 'f'; i++)
			test.push_back(i);
		test.erase(test.begin() + 3);
		print_vector(test);
		test.insert(test.begin() + 3, 'd');
		print_vector(test);
		test.pop_back();
		print_vector(test);
		std::cout << test.capacity() << std::endl;
		std::cout << test.front() << ' ' << *test.begin() << ' ' << test.back() << ' ' << *test.end() << ' ' << test.empty() << std::endl;
		print_vector(test);
		test.clear();
		std::cout << test.capacity() << std::endl;
		std::cout << "zizi" << sizeof(int) << std::endl;
		std::cout << test.front() << ' ' << *test.begin() << ' ' << *test.end() << ' ' << test.empty() << std::endl;
		print_vector(test);
	}
	{
		std::cout << "phase 3" << std::endl;

		ft::vector<int> test;
		for (size_t i = 'a'; i <= 5000; i++)
			test.push_back(i);

		std::cout << test.get_allocator().max_size() << std::endl;
		std::cout << test.max_size() << std::endl;
	}
}
