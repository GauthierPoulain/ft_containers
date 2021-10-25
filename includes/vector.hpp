#pragma once

#include "./iterators/random_access_iterator.hpp"
#include "./iterators/reverse_iterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{

	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef allocator_type &reference;
		typedef const allocator_type &const_reference;
		typedef allocator_type *pointer;
		typedef const allocator_type *const_pointer;
		typedef ft::random_access_iterator<value_type> iterator;
		typedef ft::random_access_iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<value_type> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

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
