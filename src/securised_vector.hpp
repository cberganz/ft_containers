/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:40:44 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 13:41:44 by cberganz         ###   ########.fr       */
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

template<typename T, typename Allocator>
struct PartialAllocation
{
	size_t	initialized;
	size_t  allocated;
	T		*data;
	Allocator& allocator;
	bool	defused;

	PartialAllocation(size_t size, Allocator& allocator)
		: initialized(0), allocated(0), data(0), allocator(allocator), defused(false)
	{
		data = allocator.allocate(size);
		allocated = size;
	}

	~PartialAllocation()
	{
		if (defused)
			return ;
		while (initialized)
		{
			initialized--;
			allocator.destroy(data + initialized);
		}
		allocator.deallocate(data, allocated);
	}

	template<typename Iter>
	void init(Iter first, Iter last)
	{
		while (first != last)
		{
			allocator.construct(data + initialized, *first);
			initialized++;
			first++;
		}
	}

	void defuse()
	{
		defused = true;
	}
};

template <class _Tp, class Allocator = std::allocator<_Tp> >
class vector {

public:

	typedef typename Allocator::reference			reference;
	typedef typename Allocator::const_reference		const_reference;
	typedef typename Allocator::pointer				pointer;
	typedef typename Allocator::const_pointer		const_pointer;
	typedef ft::random_access_iterator<_Tp>			iterator;
	typedef ft::random_access_iterator<const _Tp> 	const_iterator;
	typedef size_t									size_type;
	typedef std::ptrdiff_t							difference_type;
	typedef _Tp										value_type;
	typedef Allocator								allocator_type;
	typedef ft::reverse_iterator<iterator>			reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	explicit
	vector(const allocator_type &allocator = Allocator())
		: _M_allocator(allocator),
		  _M_start(NULL),
		  _M_finish(NULL),
		  _M_end_of_storage(NULL)
	{}

	explicit
	vector(size_type __n, const _Tp &__v = _Tp(), const allocator_type &allocator = Allocator())
		: _M_allocator(allocator)
	{
		if (__n > max_size())
			throw std::length_error("cannot create std::vector larger than max_size()");
		_M_start = _M_allocator.allocate(__n);
		_M_finish = _M_start;
		_M_end_of_storage = _M_start + __n;
		while (__n--)
		{
			_M_allocator.construct(_M_finish, __v);
			_M_finish++;
		}
	}

	template <class InputIterator>
	vector(InputIterator first, InputIterator last, const allocator_type &allocator = Allocator(),
		   typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = 0)
		: _M_allocator(allocator)
	{
		size_type size = ft::difference(first, last);
		if (size > max_size())
			throw std::length_error("cannot create std::vector larger than max_size()");
		_M_start = _M_allocator.allocate(size);
		_M_finish = _M_start;
		_M_end_of_storage = _M_start + size;
		while (size--)
		{
			_M_allocator.construct(_M_finish, *first++);
			_M_finish++;
		}
	}

	vector(const vector<_Tp, Allocator> &x)
		: _M_allocator(x._M_allocator),
		  _M_start(NULL),
		  _M_finish(NULL),
		  _M_end_of_storage(NULL)
	{
		this->reserve(x.capacity());
		insert(begin(), x.begin(), x.end());
	}

	~vector()
	{
		clear();
		_M_allocator.deallocate(_M_start, capacity());
	}

	vector<_Tp, Allocator> &
	operator=(const vector<_Tp, Allocator> &rhs)
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
			_M_allocator.deallocate(_M_start, capacity());
			_M_start = _M_allocator.allocate(newSize);
			_M_finish = _M_start;
			_M_end_of_storage = _M_start + newSize;
		}
		for (InputIterator it = first; it != last; it++, _M_finish++)
			_M_allocator.construct(_M_finish, *it);
	}

	void
	assign(size_type __n, const _Tp &__v)
	{
		clear();
		if (capacity() >= __n and __n != 0)
			while (__n--)
				_M_allocator.construct(_M_finish++, __v);
		else if (__n != 0)
		{
			_M_allocator.deallocate(_M_start, capacity());
			_M_start = _M_allocator.allocate(__n);
			_M_finish = _M_start;
			_M_end_of_storage = _M_start + __n;
			while (__n--)
			{
				_M_allocator.construct(_M_finish, __v);
				_M_finish++;
			}
		}
	}

	allocator_type
	get_allocator()
	const
	{
		return allocator_type(_M_allocator);
	}

	iterator
	begin()
	{
		return iterator(_M_start);
	}

	const_iterator
	begin()
	const
	{
		return const_iterator(_M_start);
	}

	iterator
	end()
	{
		return iterator(empty() ? _M_start : _M_finish);
	}

	const_iterator
	end()
	const
	{
		return const_iterator(empty() ? _M_start : _M_finish);
	}

	reverse_iterator
	rbegin()
	{
		return reverse_iterator(end());
	}

	const_reverse_iterator
	rbegin()
	const
	{
		return const_reverse_iterator(end());
	}

	reverse_iterator
	rend()
	{
		return reverse_iterator(begin());
	}

	const_reverse_iterator
	rend()
	const
	{
		return const_reverse_iterator(begin());
	}

	size_type
	size()
	const
	{
		return size_type(_M_finish - _M_start);
	}

	size_type
	max_size()
	const
	{
		return _M_allocator.max_size();
	}

	void
	resize(size_type __n, _Tp __v = _Tp())
	{
		if (__n > max_size())
			throw std::length_error("vector::resize");
		if (__n > size())
			insert(end(), __n - size(), __v);
		while (__n < size())
		{
			_M_finish--;
			_M_allocator.destroy(_M_finish);
		}
	}

	size_type
	capacity()
	const
	{
		return size_type(_M_end_of_storage - _M_start);
	}

	bool
	empty()
	const
	{
		return size() == 0 ? true : false;
	}

	void
	reserve(size_type __n)
	{
		if (__n > max_size())
			throw std::length_error("vector::reserve");
		if (__n > capacity())
		{
			PartialAllocation<value_type, allocator_type> partial_allocation(__n, _M_allocator);
			partial_allocation.init(begin(), end());
			partial_allocation.defuse();
			
			for (iterator it = begin(); it < end(); it++)
				_M_allocator.destroy(&(*it));
			
			_M_allocator.deallocate(_M_start, capacity());
			_M_start = partial_allocation.data;
			_M_finish = _M_start + partial_allocation.initialized;
			_M_end_of_storage = _M_start + __n;
		}
	}

	reference
	operator[](size_type __n)
	{
		return *(_M_start + __n);
	}

	const_reference
	operator[](size_type __n)
	const
	{
		return *(_M_start + __n);
	}

protected:

	void
	_M_range_check(size_type __n) const
	{
		if (__n >= size())
			throw std::out_of_range("vector::_M_range_check: __n "
									"(which is " + ft::toStr(__n)
									+ " >= this->size() (which is "
									+ ft::toStr(size()) + ")");
	}

public:

	const_reference
	at(size_type __n)
	const
	{
		_M_range_check(__n);
		return *(_M_start + __n);
	}

	reference
	at(size_type __n)
	{
		_M_range_check(__n);
		return *(_M_start + __n);
	}

	reference
	front()
	{ return *_M_start; }

	const_reference
	front()
	const
	{ return *_M_start; }

	reference
	back()
	{ return *(_M_finish - 1); }

	const_reference
	back()
	const
	{ return *(_M_finish - 1); }

	void
	push_back(const _Tp &__v)
	{
		if (_M_finish >= _M_end_of_storage)
			reserve(size() > 0 ? size() * 2 : 1);
		_M_allocator.construct(_M_finish, __v);
		_M_finish++;
	}

	void
	pop_back()
	{
		_M_allocator.destroy(&back());
		_M_finish--;
	}

	iterator
	insert(iterator __position, const _Tp &__v)
	{
		difference_type __offset = ft::difference(begin(), __position);
		size_type __offset2 = ft::difference(__position, end());
		if (capacity() < size() + 1)
			reserve(size() > 0 ? capacity() * 2 : 1);
		_M_allocator.construct(_M_finish, __v);
		iterator it = end();
		for (size_type i = 0; i < __offset2; it--, i++)
			*it = *(it - 1);
		*it = __v;
		_M_finish++;
		return begin() + __offset;
	}

	void
	insert(iterator __position, size_type __n, const _Tp &__v)
	{
		ft::vector<value_type> tmp(__n, __v);
		this->insert(__position, tmp.begin(), tmp.end());
	}

	template <class InputIterator>
	void
	insert(iterator __position, InputIterator __first, InputIterator __last,
		   typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = 0)
	{
		size_type __inputOffset = ft::difference(__first, __last);
		size_type __posOffset = ft::difference(__position, end());
		ft::vector<value_type> tmp(__position, end());
		if (capacity() < size() + __inputOffset)
		{
			if (this->size() == 0)
				reserve(this->size() + __inputOffset);
			else
			{
				size_type i = 2;
				while (this->size() * i < __inputOffset + this->size())
					i++;
				reserve(this->size() * i);
			}
		}
		for (size_type i = 0; i < __posOffset; i++)
			erase(end() - 1);
		for (size_type i = 0; i < __inputOffset; i++)
		{
			push_back(*__first);
			__first++;
		}
		for (iterator it = tmp.begin(); it < tmp.end(); it++)
			push_back(*it);
	}

	iterator
	erase(iterator __position)
	{
		pointer savePos = &(*__position);
		if (&(*__position) + 1 == _M_finish)
			_M_allocator.destroy(&(*__position));
		else
		{
			_M_allocator.destroy(&(*__position));
			for (int i = 0; i < _M_finish - &(*__position) - 1; i++)
			{
				_M_allocator.construct(&(*__position) + i, *(&(*__position) + i + 1));
				_M_allocator.destroy(&(*__position) + i + 1);
			}
		}
		_M_finish -= 1;
		return (iterator(savePos));
	}

	iterator
	erase(iterator __first, iterator __last)
	{
		pointer savePos = &(*__first);
		size_type __offset = ft::difference(__first, __last);
		size_type __offset2 = ft::difference(__last, this->end());
		for (iterator it = __first; it < __last; it++)
			_M_allocator.destroy(&(*it));
		for (size_type i = 0; i < __offset2 and __offset > 0; i++)
		{
			_M_allocator.construct(&(*__first) + i, *(&(*__first) + i + __offset));
			_M_allocator.destroy(&(*__first) + i + __offset);
		}
		_M_finish -= __offset;
		return (iterator(savePos));
	}

	void
	swap(vector<_Tp, Allocator> &__x)
	{
		if (__x != *this)
		{
			pointer tmp_start = __x._M_start;
			pointer tmp_finish = __x._M_finish;
			pointer tmp_end_of_storage = __x._M_end_of_storage;
			allocator_type tmp_allocator = __x._M_allocator;
			__x._M_start = _M_start;
			__x._M_finish = _M_finish;
			__x._M_end_of_storage = _M_end_of_storage;
			__x._M_allocator = _M_allocator;
			_M_start = tmp_start;
			_M_finish = tmp_finish;
			_M_end_of_storage = tmp_end_of_storage;
			_M_allocator = tmp_allocator;
		}
	}

	void
	clear()
	{
		while (_M_finish > _M_start)
		{
			_M_finish--;
			_M_allocator.destroy(_M_finish);
		}
	}

protected:

	allocator_type _M_allocator;
	pointer _M_start;
	pointer _M_finish;
	pointer _M_end_of_storage;

}; // class Vector

	template <class _Tp, class Allocator>
	bool operator==(const vector<_Tp, Allocator> &lhs,
					const vector<_Tp, Allocator> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) ? true : false);
	}

	template <class _Tp, class Allocator>
	bool operator<(const vector<_Tp, Allocator> &lhs,
				   const vector<_Tp, Allocator> &rhs)
	{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); } // + COMP ?

	template <class _Tp, class Allocator>
	bool operator!=(const vector<_Tp, Allocator> &lhs,
					const vector<_Tp, Allocator> &rhs)
	{ return not (lhs == rhs); }

	template <class _Tp, class Allocator>
	bool operator>(const vector<_Tp, Allocator> &lhs,
				   const vector<_Tp, Allocator> &rhs)
	{ return rhs < lhs; }

	template <class _Tp, class Allocator>
	bool operator>=(const vector<_Tp, Allocator> &lhs,
					const vector<_Tp, Allocator> &rhs)
	{ return not (lhs < rhs); }

	template <class _Tp, class Allocator>
	bool operator<=(const vector<_Tp, Allocator> &lhs,
					const vector<_Tp, Allocator> &rhs)
	{ return not (rhs < lhs); }

	template <class _Tp, class Allocator>
	void swap(vector<_Tp, Allocator> &x, vector<_Tp, Allocator> &y)
	{ x.swap(y); }

} // namespace ft

#endif // VECTOR_HPP