#pragma once

#include "./iterators/randomAccessIterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{

	public:
		typedef T value_type;
		typedef Alloc allocator_type;

		typedef ft::randomAccessIterator<value_type> iterator;

		vector();
		vector(size_t n, const T val);
		vector(iterator first, iterator last);
		vector(const vector &x);
		vector &operator=(const vector &x);
		~vector();

	private:
		// size_type _size;
		// size_type _volume;
		allocator_type _allocator;
		// pointer _tab;
	};

}
