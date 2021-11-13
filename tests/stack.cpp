#include <string>
#include <iostream>
#include <deque>

#ifdef STL
#include <stack>
#include <vector>
namespace ft = std;
#else
#include "../includes/stack.hpp"
#include "../includes/vector.hpp"
#endif

void stack_test()
{
	// if (false)
	{
		ft::stack<int> foo;
		ft::stack<int> bar;
		foo.push(4);
		foo.push(87);
		foo.push(54);
		bar.push(1);
		bar.push(12);
		bar.push(5);
		bar.push(87);
		bar.push(-1);
		std::cout << (foo == bar);
		std::cout << (foo != bar);
		std::cout << (foo < bar);
		std::cout << (foo > bar);
		std::cout << (foo >= bar);
		std::cout << (foo <= bar) << std::endl;
	}
	// if (false)
	{
		ft::stack<std::string> stest;
		std::cout << stest.size() << std::endl;
		std::cout << stest.empty() << std::endl;
		stest.push("everyone");
		stest.push("hello");
		stest.push("except evaluators");
		std::cout << stest.empty() << std::endl;
		std::cout << stest.size() << std::endl;
		for (int i = 0; i < 3; i++)
		{
			std::cout << stest.top() << std::endl;
			stest.pop();
		}
		std::cout << stest.empty() << std::endl;
	}
	// if (false)
	{
		ft::stack<int, ft::vector<int> > vstack;
		std::cout << vstack.size() << std::endl;
		std::cout << vstack.empty() << std::endl;
		vstack.push(1);
		vstack.push(2);
		vstack.push(3);
		std::cout << vstack.empty() << std::endl;
		std::cout << vstack.size() << std::endl;
		for (int i = 0; i < 3; i++)
		{
			std::cout << vstack.top() << std::endl;
			vstack.pop();
		}
		std::cout << vstack.empty() << std::endl;
	}
	// if (false)
	{
		ft::stack<int, std::deque<int> > dstack;
		std::cout << dstack.size() << std::endl;
		std::cout << dstack.empty() << std::endl;
		dstack.push(1);
		dstack.push(2);
		dstack.push(3);
		std::cout << dstack.empty() << std::endl;
		std::cout << dstack.size() << std::endl;
		for (int i = 0; i < 3; i++)
		{
			std::cout << dstack.top() << std::endl;
			dstack.pop();
		}
		std::cout << dstack.empty() << std::endl;
	}
	// if (false)
	{
		ft::stack<int> sped;
		for (int i = 0; i < 15000000; i++)
		{
			sped.push(i);
			if (i % 1000000 == 0)
				std::cout << sped.size() << ' ' << sped.top() << std::endl;
		}
		std::cout << sped.size() << std::endl;
		while (sped.size() > 0)
			sped.pop();
		std::cout << sped.size() << std::endl;
	}
	// if (false)
	{
		ft::stack<int> *test = new ft::stack<int>();
		for (int i = 0; i < 10; i++)
			test->push(i * i);
		ft::stack<int> *copy = new ft::stack<int>(*test);
		ft::stack<int> *assign;
		assign = test;
		std::cout << assign->top() << ' ' << assign->size() << ' ';
		std::cout << test->top() << ' ' << assign->size() << ' ';
		std::cout << copy->top() << ' ' << copy->size() << std::endl;
		test->push(72);
		std::cout << assign->top() << ' ' << assign->size() << ' ';
		std::cout << test->top() << ' ' << assign->size() << ' ';
		std::cout << copy->top() << ' ' << copy->size() << std::endl;
		while (test->size())
		{
			std::cout << test->top() << std::endl;
			test->pop();
		}
		while (copy->size())
		{
			std::cout << copy->top() << std::endl;
			copy->pop();
		}
		delete test;
		delete copy;
	}
}
