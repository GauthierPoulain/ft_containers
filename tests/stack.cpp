#include "../includes/vector.hpp"
#include "../includes/stack.hpp"
#include <vector>
#include <stack>
#include <list>
#include <deque>
#include <string>
#include <iostream>

#define PURPLE "\e[35m"
#define GREEN "\e[32m"
#define RED "\e[31;1m"
#define RESET "\e[0m"

void operators_stack()
{
	std::cout << PURPLE << "ft - " << std::endl;
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

	if (foo == bar)
		std::cout << "foo and bar are equal\n";
	if (foo != bar)
		std::cout << "foo and bar are not equal\n";
	if (foo < bar)
		std::cout << "foo is less than bar\n";
	if (foo > bar)
		std::cout << "foo is greater than bar\n";
	if (foo <= bar)
		std::cout << "foo is less than or equal to bar\n";
	if (foo >= bar)
		std::cout << "foo is greater than or equal to bar\n";

	std::cout << GREEN << "std - " << std::endl;
	ft::stack<int> foo2;
	ft::stack<int> bar2;

	foo2.push(4);
	foo2.push(87);
	foo2.push(54);

	bar2.push(1);
	bar2.push(12);
	bar2.push(5);
	bar2.push(87);
	bar2.push(-1);
	if (foo2 == bar2)
		std::cout << "foo and bar are equal\n";
	if (foo2 != bar2)
		std::cout << "foo and bar are not equal\n";
	if (foo2 < bar2)
		std::cout << "foo is less than bar\n";
	if (foo2 > bar2)
		std::cout << "foo is greater than bar\n";
	if (foo2 <= bar2)
		std::cout << "foo is less than or equal to bar\n";
	if (foo2 >= bar2)
		std::cout << "foo is greater than or equal to bar\n";
}

void stack_test()
{
	std::cout << "--------------------------------------------------------------------" << std::endl;
	std::cout << RESET << "\nSTACK TEST" << std::endl
			  << std::endl;

	ft::stack<std::string> s1;
	std::stack<std::string> s2;

	std::cout << PURPLE << "empty : " << s1.empty() << "  - ft" << std::endl;
	std::cout << GREEN << "empty : " << s2.empty() << "  - std" << std::endl;

	std::cout << PURPLE << "size : " << s1.size() << "  - ft" << std::endl;
	std::cout << GREEN << "size : " << s2.size() << "  - std" << std::endl;

	std::cout << RESET << "push \'hey\' \'lol\' \'pouic\'" << std::endl;
	s1.push("hey");
	s1.push("lol");
	s1.push("pouic");

	s2.push("hey");
	s2.push("lol");
	s2.push("pouic");

	std::cout << PURPLE << "empty : " << s1.empty() << "  - ft" << std::endl;
	std::cout << GREEN << "empty : " << s2.empty() << "  - std" << std::endl;

	std::cout << PURPLE << "size : " << s1.size() << "  - ft" << std::endl;
	std::cout << GREEN << "size : " << s2.size() << "  - std" << std::endl;

	std::cout << PURPLE << "top : " << s1.top() << "  - ft" << std::endl;
	std::cout << GREEN << "top : " << s2.top() << "  - std" << std::endl;

	std::cout << RESET << "pop" << std::endl;

	s1.pop();
	s2.pop();

	std::cout << PURPLE << "top : " << s1.top() << "  - ft" << std::endl;
	std::cout << GREEN << "top : " << s2.top() << "  - std" << std::endl;

	operators_stack();

	std::cout << RESET << "-----------------" << std::endl;

	std::cout << "with std vector" << std::endl;

	ft::stack<int, std::vector<int> > vec;

	vec.push(5);
	vec.push(7);
	vec.push(8);

	for (int i = 0; i < 3; i++)
	{
		std::cout << PURPLE << vec.top() << ' ';
		vec.pop();
	}
	std::cout << std::endl;

	std::cout << RESET << "-----------------" << std::endl;

	std::cout << "with std deque" << std::endl;

	ft::stack<int, std::deque<int> > dec;

	dec.push(5);
	dec.push(7);
	dec.push(8);

	for (int i = 0; i < 3; i++)
	{
		std::cout << PURPLE << dec.top() << ' ';
		dec.pop();
	}
	std::cout << std::endl;

	std::cout << RESET << "-----------------" << std::endl;

	std::cout << "with std list" << std::endl;

	ft::stack<int, std::deque<int> > lec;

	lec.push(5);
	lec.push(7);
	lec.push(8);

	for (int i = 0; i < 3; i++)
	{
		std::cout << PURPLE << lec.top() << ' ';
		lec.pop();
	}
	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------------" << std::endl;
}