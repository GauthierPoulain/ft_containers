#pragma once

#include <iterator>

namespace ft
{
	template <class T>
	class random_access_iterator
	{
	public:
		typedef T value_type;
		typedef T &reference;
		typedef T *pointer;
		// typedef std::ptr

		random_access_iterator() : _it(NULL) {}
		random_access_iterator(pointer ptr) : _it(ptr) {}
		random_access_iterator(const random_access_iterator &copy) : _it(copy._it) {}
		~random_access_iterator() {}

		random_access_iterator &operator=(const random_access_iterator &copy)
		{
			_it = copy._it;
			return *this;
		}

	private:
		pointer _it;
	};
}
