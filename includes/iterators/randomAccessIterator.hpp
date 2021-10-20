#pragma once

#include <iterator>

namespace ft
{
	template <class T>
	class randomAccessIterator
	{
	public:
		typedef T value_type;
		typedef T &reference;
		typedef T *pointer;
		// typedef std::ptr

		randomAccessIterator() : _it(NULL) {}
		randomAccessIterator(pointer ptr) : _it(ptr) {}
		randomAccessIterator(const randomAccessIterator &copy) : _it(copy._it) {}
		~randomAccessIterator() {}

		randomAccessIterator &operator=(const randomAccessIterator &copy)
		{
			_it = copy._it;
			return *this;
		}

	private:
		pointer _it;
	};
}
