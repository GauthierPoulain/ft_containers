#pragma once

#include <memory>
#include "./utils/commons.hpp"
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

		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		typedef ft::random_access_iterator<value_type> iterator;
		typedef ft::random_access_iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<value_type> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
		typedef size_t size_type;

		explicit vector(const allocator_type &alloc = allocator_type()) : _size(0), _volume(0), _allocator(alloc), _tab(NULL) {}

		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _size(n), _volume(n), _allocator(alloc), _tab(NULL)
		{
			_tab = _allocator.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(&_tab[i], val);
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
			   typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL) : _size(0), _volume(0), _allocator(alloc), _tab(NULL)
		{
			_size = last - first;
			_volume = _size;
			_tab = _allocator.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(&_tab[i], *(first + i));
		}

		vector(const vector &x) : _size(0)
		{
			_size = x._size;
			_volume = x._volume;
			_allocator = x._allocator;
			_tab = _allocator.allocate(_volume);
			for (size_t i = 0; i < _size; i++)
				_allocator.construct(&_tab[i], x._tab[i]);
		}

		~vector() { _allocator.deallocate(_tab, _size); }

		vector &operator=(const vector &x)
		{
			_size = x._size;
			_volume = x._volume;
			_allocator = x._allocator;
			_tab = x._tab;
			return *this;
		}

		iterator begin() { return iterator(_tab); }
		const_iterator begin() const { return const_iterator(_tab); }
		iterator end() { return iterator(&_tab[_size]); }
		const_iterator end() const { return const_iterator(&_tab[_size]); }

		void swap(vector &x)
		{
			size_type tmpSize = x._size;
			size_type tmpVolume = x._volume;
			allocator_type tmpAllocator = x._allocator;
			pointer tmpTab = x._tab;

			x._size = _size;
			x._volume = _volume;
			x._allocator = _allocator;
			x._tab = _tab;

			_size = tmpSize;
			_volume = tmpVolume;
			_allocator = tmpAllocator;
			_tab = tmpTab;
		}

	private:
		size_type _size;
		size_type _volume;
		allocator_type _allocator;
		pointer _tab;
	};

}
