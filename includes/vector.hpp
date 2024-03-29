#pragma once

#include <memory>
#include <limits>
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
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
		typedef size_t size_type;

		explicit vector(const allocator_type &alloc = allocator_type()) : _size(0), _volume(0), _allocator(alloc), _tab(NULL)
		{
		}

		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _size(n), _volume(n), _allocator(alloc), _tab(NULL)
		{
			_tab = _allocator.allocate(_volume);
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
			vector tmp(x);
			swap(x);
			return *this;
		}

		iterator begin() { return iterator(_tab); }

		const_iterator begin() const { return const_iterator(_tab); }

		iterator end() { return iterator(&_tab[_size]); }

		const_iterator end() const { return const_iterator(&_tab[_size]); }

		reverse_iterator rbegin() { return reverse_iterator(end()); }

		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

		reverse_iterator rend() { return reverse_iterator(begin()); }

		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

		size_type size() const { return _size; }

		size_type max_size() const
		{
			return std::min<size_type>(_allocator.max_size(),
									   std::numeric_limits<difference_type>::max());
		}

		void resize(size_type n, value_type val = value_type())
		{
			if (n > max_size())
				throw(std::length_error("vector::resize"));
			else if (n < _size)
			{
				for (size_type i = n; i < _size; i++)
					_allocator.destroy(&_tab[i]);
				_size = n;
			}
			else
				insert(end(), n - _size, val);
		}

		size_type capacity() const { return _volume; }

		bool empty() const { return _size == 0; }

		void reserve(size_type n)
		{
			if (n > max_size())
				throw std::length_error("vector::reserve");
			else if (n > _volume)
			{
				value_type *buf = _allocator.allocate(n);
				for (size_type i = 0; i < _size; i++)
				{
					_allocator.construct(&buf[i], _tab[i]);
					_allocator.destroy(&_tab[i]);
				}
				if (_tab)
					_allocator.deallocate(_tab, _volume);
				_tab = buf;
				_volume = n;
			}
		}

		reference operator[](size_type n)
		{
			reference idx = *(_tab + n);
			return idx;
		}

		reference at(size_type n)
		{
			if (n >= _size)
				throw std::out_of_range("Error: you're trying to acceed to an out of ranage element!");
			return _tab[n];
		}
		const_reference at(size_type n) const
		{
			if (n >= _size)
				throw std::out_of_range("Error: you're trying to acceed to an out of ranage element!");
			return _tab[n];
		}

		reference front() { return _tab[0]; }

		const_reference front() const { return _tab[0]; }

		reference back() { return _tab[_size - 1]; }

		const_reference back() const { return _tab[_size - 1]; }

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL)
		{
			size_type newSize = last - first;
			if (newSize > _size)
				reserve(_getValidSize(newSize));
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(&_tab[i]);
			_size = newSize;
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(&_tab[i], *(first + i));
		}
		void assign(size_type n, const value_type &val)
		{
			if (n > _size)
				reserve(_getValidSize(n));
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(&_tab[i]);
			_size = n;
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(&_tab[i], val);
		}

		void push_back(const value_type &val)
		{
			insert(end(), val);
		}

		void pop_back()
		{
			_allocator.destroy(&_tab[_size - 1]);
			_size--;
		}

		iterator insert(iterator position, const value_type &val)
		{
			size_type dist = position - begin();
			if (_size + 1 > _volume)
				_reAlloc();
			_size++;
			for (size_type i = _size - 1; i > dist; i--)
				_allocator.construct(&_tab[i], _tab[i - 1]);
			_allocator.construct(&_tab[dist], val);
			return iterator(begin() + dist);
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			size_type dist = position - begin();
			if (_size + n > _volume)
				reserve(_getValidSize(_size + n));
			if (_size > 0)
			{
				for (size_type i = _size - 1; i > dist; i--)
					_allocator.construct(&_tab[i], _tab[i - n]);
			}
			_size += n;
			for (size_type i = dist; i < _size; i++)
				_allocator.construct(&_tab[i], val);
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL)
		{
			size_type dist = position - begin();
			size_type n = last - first;
			if (_size + n > _volume)
			{
				if (n > _size)
					reserve(_getValidSize(_size + n));
				else
					_reAlloc();
			}
			_size += n;
			for (size_type i = _size - 1; i > dist; i--)
				_allocator.construct(&_tab[i], _tab[i - n]);
			for (size_type i = 0; i < n; i++)
				_allocator.construct(&_tab[dist + i], *(first + i));
		}

		iterator erase(iterator position)
		{
			size_type dist = position - begin();
			_allocator.destroy(&_tab[dist]);
			for (size_type i = dist; i < _size; i++)
			{
				_allocator.construct(&_tab[i], _tab[i + 1]);
				_allocator.destroy(&_tab[i + 1]);
			}
			_size--;
			return begin() + dist;
		}

		iterator erase(iterator first, iterator last)
		{
			size_type dist = first - begin();
			size_type n = last - first;
			for (size_type i = 0; i < n; i++)
				_allocator.destroy(&_tab[dist + i]);
			for (size_type i = dist; i < _size; i++)
			{
				_allocator.construct(&_tab[i], _tab[i + n]);
				_allocator.destroy(&_tab[i + n]);
			}
			_size -= n;
			return begin() + dist;
		}

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

		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(&_tab[i]);
			_size = 0;
		}

		allocator_type get_allocator() const
		{
			allocator_type ret(_allocator);
			return ret;
		}

	private:
		void _reAlloc()
		{
			reserve(_getValidSize((_volume > 0) ? (_volume * 2) : 1));
		}
		size_t _getValidSize(size_t n)
		{
#ifdef __APPLE__
			if ((n & (n - 1)) != 0)
				return n;
			size_t newSize = 1;
			while (newSize < n)
				newSize *= 2;
			return newSize;
#else
			return n;
#endif
		}
		size_type _size;
		size_type _volume;
		allocator_type _allocator;
		pointer _tab;
	};
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() == rhs.size())
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		return false;
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(rhs > lhs);
	}

	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
	{
		x.swap(y);
	}
}
