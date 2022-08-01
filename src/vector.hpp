/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:40:44 by cberganz          #+#    #+#             */
/*   Updated: 2022/08/01 13:00:58 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "utility/utils.hpp"
# include "utility/random_access_iterator.hpp"
# include "utility/reverse_iterator.hpp"
# include "utility/lexicographical_compare.hpp"
# include "utility/equal.hpp"
# include <algorithm>

namespace ft
{

template <class T, class Allocator = std::allocator<T> >
class vector {

public:
	typedef typename Allocator::reference			reference;
	typedef typename Allocator::const_reference		const_reference;
	typedef typename Allocator::pointer				pointer;
	typedef typename Allocator::const_pointer		const_pointer;
	typedef ft::random_access_iterator<T>			iterator;
	typedef ft::random_access_iterator<const T> 	const_iterator;
	typedef size_t									size_type;
	typedef std::ptrdiff_t							difference_type;
	typedef T										value_type;
	typedef Allocator								allocator_type;
	typedef ft::reverse_iterator<iterator>			reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	explicit
	vector(const allocator_type &_allocator = Allocator())
		: allocator(_allocator),
		  start(NULL),
		  finish(NULL),
		  end_of_storage(NULL)
	{}

	explicit
	vector(size_type n, const T &v = T(), const allocator_type &_allocator = Allocator())
		: allocator(_allocator)
	{
		if (n > max_size())
			throw std::length_error("cannot create std::vector larger than max_size()");
		start = allocator.allocate(n);
		finish = start;
		end_of_storage = start + n;
		while (n--)
		{
			allocator.construct(finish, v);
			finish++;
		}
	}

	template <class InputIterator>
	vector(InputIterator first, InputIterator last, const allocator_type &_allocator = Allocator(),
		   typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = 0)
		: allocator(_allocator)
	{
		size_type size = ft::difference(first, last);
		if (size > max_size())
			throw std::length_error("cannot create std::vector larger than max_size()");
		start = allocator.allocate(size);
		finish = start;
		end_of_storage = start + size;
		while (size--)
		{
			allocator.construct(finish, *first++);
			finish++;
		}
	}

	vector(const vector<T, Allocator> &x)
		: allocator(x.allocator),
		  start(NULL),
		  finish(NULL),
		  end_of_storage(NULL)
	{
		this->reserve(x.capacity());
		insert(begin(), x.begin(), x.end());
	}

	~vector()
	{
		clear();
		allocator.deallocate(start, capacity());
	}

	vector<T, Allocator> &
	operator=(const vector<T, Allocator> &rhs)
	{
		if (*this != rhs)
		{
			clear();
			this->reserve(rhs.size());
			insert(begin(), rhs.begin(), rhs.end());
		}
		return *this;
	}

	template <typename InputIterator>
	void assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = 0)
	{
		clear();
		size_type newSize = ft::difference(first, last);
		if (capacity() < newSize)
		{
			allocator.deallocate(start, capacity());
			start = allocator.allocate(newSize);
			finish = start;
			end_of_storage = start + newSize;
		}
		for (InputIterator it = first; it != last; it++, finish++)
			allocator.construct(finish, *it);
	}

	void
	assign(size_type n, const T &v)
	{
		clear();
		if (capacity() >= n and n != 0)
			while (n--)
				allocator.construct(finish++, v);
		else if (n != 0)
		{
			allocator.deallocate(start, capacity());
			start = allocator.allocate(n);
			finish = start;
			end_of_storage = start + n;
			while (n--)
			{
				allocator.construct(finish, v);
				finish++;
			}
		}
	}

	allocator_type
	get_allocator()
	const
	{ return allocator_type(allocator); }

	iterator
	begin()
	{ return iterator(start); }

	const_iterator
	begin()
	const
	{ return const_iterator(start); }

	iterator
	end()
	{ return iterator(empty() ? start : finish); }

	const_iterator
	end()
	const
	{ return const_iterator(empty() ? start : finish); }

	reverse_iterator
	rbegin()
	{ return reverse_iterator(end()); }

	const_reverse_iterator
	rbegin()
	const
	{ return const_reverse_iterator(end()); }

	reverse_iterator
	rend()
	{ return reverse_iterator(begin()); }

	const_reverse_iterator
	rend()
	const
	{ return const_reverse_iterator(begin()); }

	size_type
	size()
	const
	{ return size_type(finish - start); }

	size_type
	max_size()
	const
	{ return allocator.max_size(); }

	void
	resize(size_type n, T v = T())
	{
		if (n > max_size())
			throw std::length_error("vector::resize");
		if (n > size())
			insert(end(), n - size(), v);
		while (n < size())
		{
			finish--;
			allocator.destroy(finish);
		}
	}

	size_type
	capacity()
	const
	{ return size_type(end_of_storage - start); }

	bool
	empty()
	const
	{ return size() == 0 ? true : false; }

	void
	reserve(size_type n)
	{
		if (n > max_size())
			throw std::length_error("vector::reserve");
		if (n > capacity())
		{
			pointer newStart = allocator.allocate(n);
			pointer newFinish = newStart;
			for (iterator it = begin(); it < end(); it++)
			{
				allocator.construct(newFinish, *it);
				allocator.destroy(&(*it));
				newFinish++;
			}
			allocator.deallocate(start, capacity());
			start = newStart;
			finish = newFinish;
			end_of_storage = start + n;
		}
	}

	reference
	operator[](size_type n)
	{ return *(start + n); }

	const_reference
	operator[](size_type n)
	const
	{ return *(start + n); }

protected:
	void
	_M_range_check(size_type n) const
	{
		if (n >= size())
			throw std::out_of_range("vector::_M_range_check: __n "
									"(which is " + ft::toStr(n)
									+ " >= this->size() (which is "
									+ ft::toStr(size()) + ")");
	}

public:
	const_reference
	at(size_type n)
	const
	{
		_M_range_check(n);
		return *(start + n);
	}

	reference
	at(size_type n)
	{
		_M_range_check(n);
		return *(start + n);
	}

	reference
	front()
	{ return *start; }

	const_reference
	front()
	const
	{ return *start; }

	reference
	back()
	{ return *(finish - 1); }

	const_reference
	back()
	const
	{ return *(finish - 1); }

	void
	push_back(const T &v)
	{
		if (finish >= end_of_storage)
			reserve(size() > 0 ? size() * 2 : 1);
		allocator.construct(finish, v);
		finish++;
	}

	void
	pop_back()
	{
		allocator.destroy(&back());
		finish--;
	}

	iterator
	insert(iterator position, const T &v)
	{
		difference_type offset = ft::difference(begin(), position);
		size_type offset2 = ft::difference(position, end());
		if (capacity() < size() + 1)
			reserve(size() > 0 ? capacity() * 2 : 1);
		allocator.construct(finish, v);
		iterator it = end();
		for (size_type i = 0; i < offset2; it--, i++)
			*it = *(it - 1);
		*it = v;
		finish++;
		return begin() + offset;
	}

	void
	insert(iterator position, size_type n, const T &v)
	{
		ft::vector<value_type> tmp(n, v);
		this->insert(position, tmp.begin(), tmp.end());
	}

	template <class InputIterator>
	void
	insert(iterator position, InputIterator first, InputIterator last,
		   typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = 0)
	{
		size_type inputOffset = ft::difference(first, last);
		size_type posOffset = ft::difference(position, end());
		ft::vector<value_type> tmp(position, end());
		if (capacity() < size() + inputOffset)
		{
			if (this->size() == 0)
				reserve(this->size() + inputOffset);
			else
			{
				size_type i = 2;
				while (this->size() * i < inputOffset + this->size())
					i++;
				reserve(this->size() * i);
			}
		}
		for (size_type i = 0; i < posOffset; i++)
			erase(end() - 1);
		for (size_type i = 0; i < inputOffset; i++)
		{
			push_back(*first);
			first++;
		}
		for (iterator it = tmp.begin(); it < tmp.end(); it++)
			push_back(*it);
	}

	iterator
	erase(iterator position)
	{
		pointer savePos = &(*position);
		if (&(*position) + 1 == finish)
			allocator.destroy(&(*position));
		else
		{
			allocator.destroy(&(*position));
			for (int i = 0; i < finish - &(*position) - 1; i++)
			{
				allocator.construct(&(*position) + i, *(&(*position) + i + 1));
				allocator.destroy(&(*position) + i + 1);
			}
		}
		finish -= 1;
		return (iterator(savePos));
	}

	iterator
	erase(iterator first, iterator last)
	{
		pointer savePos = &(*first);
		size_type offset = ft::difference(first, last);
		size_type offset2 = ft::difference(last, this->end());
		for (iterator it = first; it < last; it++)
			allocator.destroy(&(*it));
		for (size_type i = 0; i < offset2 and offset > 0; i++)
		{
			allocator.construct(&(*first) + i, *(&(*first) + i + offset));
			allocator.destroy(&(*first) + i + offset);
		}
		finish -= offset;
		return (iterator(savePos));
	}

	void
	swap(vector<T, Allocator> &x)
	{
		if (x != *this)
		{
			pointer tmp_start = x.start;
			pointer tmp_finish = x.finish;
			pointer tmp_end_of_storage = x.end_of_storage;
			allocator_type tmp_allocator = x.allocator;
			x.start = start;
			x.finish = finish;
			x.end_of_storage = end_of_storage;
			x.allocator = allocator;
			start = tmp_start;
			finish = tmp_finish;
			end_of_storage = tmp_end_of_storage;
			allocator = tmp_allocator;
		}
	}

	void
	clear()
	{
		while (finish > start)
		{
			finish--;
			allocator.destroy(finish);
		}
	}

protected:
	allocator_type	allocator;
	pointer			start;
	pointer			finish;
	pointer			end_of_storage;

}; // class Vector

template <class T, class Allocator>
inline bool
operator==(const vector<T, Allocator> &lhs,
		   const vector<T, Allocator> &rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) ? true : false);
}

template <class T, class Allocator>
inline bool
operator<(const vector<T, Allocator> &lhs,
		  const vector<T, Allocator> &rhs)
{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

template <class T, class Allocator>
inline bool
operator!=(const vector<T, Allocator> &lhs,
		   const vector<T, Allocator> &rhs)
{ return not (lhs == rhs); }

template <class T, class Allocator>
inline bool
operator>(const vector<T, Allocator> &lhs,
	      const vector<T, Allocator> &rhs)
{ return rhs < lhs; }

template <class T, class Allocator>
inline bool
operator>=(const vector<T, Allocator> &lhs,
		   const vector<T, Allocator> &rhs)
{ return not (lhs < rhs); }

template <class T, class Allocator>
inline bool
operator<=(const vector<T, Allocator> &lhs,
		   const vector<T, Allocator> &rhs)
{ return not (rhs < lhs); }

template <class T, class Allocator>
void swap(vector<T, Allocator> &x, vector<T, Allocator> &y)
{ x.swap(y); }

} // namespace ft

#endif // VECTOR_HPP