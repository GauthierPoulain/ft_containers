#include <string>
#include <iostream>
#include <sstream>

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

std::string itoa(int a)
{
	std::ostringstream temp;
	temp << a;
	return temp.str();
}

void vector_test()
{
	// if (false)
	{
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
	// if (false)
	{
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
	// if (false)
	{
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
		std::cout << test.front() << ' ' << *test.begin() << ' ' << test.back() << ' ' << *(test.end() - 1) << ' ' << test.empty() << std::endl;
		std::cout << *test.rbegin() << ' ' << *(test.rend() - 1) << ' ' << test.capacity() << std::endl;
		print_vector(test);
		test.clear();
		std::cout << test.size() << ' ' << test.capacity() << ' ' << test.empty() << std::endl;
		print_vector(test);
	}
	// if (false)
	{
		ft::vector<int> itest;
		for (size_t i = 0; i <= 10; i++)
			itest.push_back(i);
		ft::vector<char> ctest;
		for (size_t i = 0; i <= 10; i++)
			ctest.push_back(i);
		ft::vector<std::string> stest;
		for (size_t i = 0; i <= 10; i++)
			stest.push_back(itoa(i));
		std::cout << itest.get_allocator().max_size() << std::endl;
		std::cout << itest.max_size() << std::endl;
		std::cout << ctest.get_allocator().max_size() << std::endl;
		std::cout << ctest.max_size() << std::endl;
		std::cout << stest.get_allocator().max_size() << std::endl;
		std::cout << stest.max_size() << std::endl;
	}
	// if (false)
	{
		ft::vector<char> test;
		for (size_t i = 0; i <= 4; i++)
			test.push_back('a' + 1);
		std::cout << test.capacity() << ' ' << test.empty() << ' ' << test.size() << ' ' << test.get_allocator().max_size() << ' ' << test.max_size() << std::endl;
		test.resize(10);
		test.reserve(10);
		std::cout << test.capacity() << ' ' << test.empty() << ' ' << test.size() << ' ' << test.get_allocator().max_size() << ' ' << test.max_size() << std::endl;
		test.push_back('a');
		test.push_back('a');
		test.push_back('a');
		std::cout << test.capacity() << ' ' << test.empty() << ' ' << test.size() << ' ' << test.get_allocator().max_size() << ' ' << test.max_size() << std::endl;
	}
	// if (false)
	{
		ft::vector<int> test;
		size_t last = -1;
		for (size_t i = 0; i <= 100000000; i++)
		{
			test.push_back(i);
			if (last != test.capacity())
			{
				std::cout << i << ' ' << test.capacity() << ' ' << test.empty() << ' ' << test.size() << std::endl;
				last = test.capacity();
			}
		}
		std::cout << test.capacity() << ' ' << test.empty() << ' ' << test.size() << ' ' << test.get_allocator().max_size() << ' ' << test.max_size() << std::endl;
	}
}
