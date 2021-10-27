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
		typedef std::ptrdiff_t difference_type;
		typedef std::random_access_iterator_tag iterator_category;

		random_access_iterator() : _it(NULL) {}
		random_access_iterator(pointer ptr) : _it(ptr) {}
		random_access_iterator(const random_access_iterator &copy) : _it(copy._it) {}
		~random_access_iterator() {}

		random_access_iterator &operator=(const random_access_iterator &copy)
		{
			_it = copy._it;
			return *this;
		}

		operator random_access_iterator<value_type const>() const
		{
			return random_access_iterator<value_type const>(_it);
		}

		bool operator==(const random_access_iterator &it) const { return _it == it._it; }
		bool operator!=(const random_access_iterator &it) const { return _it != it._it; }
		bool operator<(const random_access_iterator &it) const { return _it < it._it; }
		bool operator>(const random_access_iterator &it) const { return _it > it._it; }
		bool operator<=(const random_access_iterator &it) const { return _it <= it._it; }
		bool operator>=(const random_access_iterator &it) const { return _it >= it._it; }

		pointer operator->() const { return _it; }
		reference operator*() const { return *_it; }

		random_access_iterator &operator++()
		{
			++_it;
			return *this;
		}

		random_access_iterator operator++(int)
		{
			random_access_iterator tmp(*this);
			++_it;
			return tmp;
		}

		random_access_iterator &operator--()
		{
			--_it;
			return *this;
		}

		random_access_iterator operator--(int)
		{
			random_access_iterator tmp(*this);
			--_it;
			return tmp;
		}

		random_access_iterator &operator+=(difference_type n)
		{
			_it += n;
			return *this;
		}

		random_access_iterator &operator-=(difference_type n)
		{
			_it -= n;
			return *this;
		}

		

	private:
		pointer _it;
	};
}
