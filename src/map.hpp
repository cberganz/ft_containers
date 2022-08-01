/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:49:32 by cberganz          #+#    #+#             */
/*   Updated: 2022/08/01 00:41:14 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <algorithm>
# include <iostream>
# include <functional>
# include <memory>
# include "RBTree.hpp"
# include "utility/pair.hpp"
# include "utility/reverse_iterator.hpp"

namespace ft {

template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
class map {

	public:
	typedef Key														key_type;
	typedef T														mapped_type;
	typedef ft::pair<const Key, T>									value_type;
	typedef Compare													key_compare;

	private:
	class value_compare : public std::binary_function<value_type, value_type, bool> {

		friend class map<Key, T, Compare, Allocator>;

		protected:
		Compare comp;
		value_compare(Compare c) : comp(c) {}

		public:
		bool operator()(const value_type& x, const value_type& y) const
		{ return comp(x.first, y.first); }

		bool operator()(const key_type& x, const value_type& y) const
		{ return comp(x, y.first); }

		bool operator()(const value_type& x, const key_type& y) const
		{ return comp(x.first, y); }

	};	// class value_compare
	
	struct KeyOfValue : public std::unary_function<value_type, typename value_type::first_type> {

		typename value_type::first_type &
		operator()(value_type & x)
		const
		{ return x.first; }

		const typename value_type::first_type &
		operator()(const value_type & x)
		const
		{ return x.first; }	

	};	// struct getKeyOfValue

	typedef ft::RBTree<key_type, KeyOfValue, value_type, value_compare, Allocator>	RBTree;

	public:
	typedef typename RBTree::allocator_type				allocator_type;
	typedef typename RBTree::reference					reference;
	typedef typename RBTree::const_reference			const_reference;
	typedef typename RBTree::size_type					size_type;
	typedef typename RBTree::pointer					pointer;
	typedef typename RBTree::const_pointer				const_pointer;
	typedef typename RBTree::iterator					iterator;
	typedef typename RBTree::const_iterator				const_iterator;
	typedef typename RBTree::reverse_iterator			reverse_iterator;
	typedef typename RBTree::const_reverse_iterator		const_reverse_iterator;
	typedef typename RBTree::difference_type			difference_type;

	protected:
	RBTree			_RBTree;

	public:
	explicit
	map(const Compare& compare = Compare(), const Allocator& allocator = Allocator())
		: _RBTree(value_compare(compare), allocator)
	{}

	template <class InputIterator>
	map(InputIterator first, InputIterator last,
		const Compare& compare = Compare(), const Allocator& allocator = Allocator())
		: _RBTree(first, last, value_compare(compare), allocator)
	{}

	map(const map<Key, T, Compare, Allocator>& src)
		: _RBTree(src.begin(), src.end(), value_compare(src.value_comp()), src._RBTree.get_allocator())
	{}

	~map()
	{ clear(); }

	map<Key, T, Compare, Allocator> &
	operator=(const map<Key, T, Compare, Allocator> &rhs)
	{
		if (this == &rhs)
			return *this;
		clear();
		insert(rhs.begin(), rhs.end());
		return *this;
	}

	/******************************
				iterators
	******************************/

	iterator
	begin()
	{ return _RBTree.begin(); }

	const_iterator
	begin()
	const
	{ return _RBTree.begin(); }

	iterator
	end()
	{ return _RBTree.end(); }

	const_iterator
	end()
	const
	{ return _RBTree.end(); }

	reverse_iterator
	rbegin()
	{ return _RBTree.rbegin(); }

	const_reverse_iterator
	rbegin()
	const
	{ return _RBTree.rbegin(); }

	reverse_iterator
	rend()
	{ return _RBTree.rend(); }

	const_reverse_iterator
	rend()
	const
	{ return _RBTree.rend(); }

	/******************************
				capacity
	******************************/

	bool 
	empty()
	const
	{ return _RBTree.empty(); }

	size_type
	size()
	const
	{ return _RBTree.size(); }

	size_type
	max_size()
	const
	{ return _RBTree.max_size(); }

	/******************************
			element access
	******************************/

	T &
	operator[](const key_type &k)
	{
		iterator it = lower_bound(k);
		if (it == end() or Compare()(k, (*it).first))
		      it = insert(it, value_type(k, mapped_type()));
		return (*it).second;
	}

	/******************************
				modifiers
	******************************/

	ft::pair<iterator, bool>
	insert(const value_type& x)
	{ return _RBTree.insert(x); }

	iterator
	insert(iterator position, const value_type& x)
	{ return _RBTree.insert(position, x); }

	template <class InputIterator>
	void
	insert(InputIterator first, InputIterator last)
	{ _RBTree.insert(first, last); }

	size_type
	erase(const key_type& x)
	{ return _RBTree.erase(x); }

	void
	erase(iterator position)
	{ _RBTree.erase(position); }

	void
	erase(iterator first, iterator last)
	{ _RBTree.erase(first, last); }

	void
	swap(map<Key, T, Compare, Allocator> &other)
	{ _RBTree.swap(other._RBTree); }

	void
	clear()
	{ _RBTree.clear(); }

	/******************************
				observers
	******************************/

	key_compare
	key_comp()
	const
	{ return Compare(); }

	value_compare
	value_comp()
	const
	{ return _RBTree.key_comp(); }

	/******************************
				operations
	******************************/

	iterator
	find(const key_type& x)
	{ return _RBTree.find(x); }

	const_iterator
	find(const key_type& x)
	const
	{ return _RBTree.find(x); }

	size_type
	count(const key_type& x)
	const	
	{ return _RBTree.count(x); }

	iterator
	lower_bound(const key_type& x)
	{ return _RBTree.lower_bound(x); }

	const_iterator
	lower_bound(const key_type& x)
	const
	{ return _RBTree.lower_bound(x); }

	iterator
	upper_bound(const key_type& x)
	{ return _RBTree.upper_bound(x); }

	const_iterator
	upper_bound(const key_type& x)
	const
	{ return _RBTree.upper_bound(x); }

	ft::pair<iterator, iterator>
	equal_range(const key_type& x)
	{ return _RBTree.equal_range(x); }

	ft::pair<const_iterator, const_iterator>
	equal_range(const key_type& x)
	const
	{ return _RBTree.equal_range(x); }

	template <class _Key, class _T, class _Compare, class _Allocator>
	friend
	bool
	operator==(const map<_Key, _T, _Compare, _Allocator>& lhs,
			   const map<_Key, _T, _Compare, _Allocator>& rhs);

	template <class _Key, class _T, class _Compare, class _Allocator>
	friend
	bool
	operator<(const map<_Key, _T, _Compare, _Allocator>& lhs,
			  const map<_Key, _T, _Compare, _Allocator>& rhs);

	/******************************
				allocator
	******************************/

	allocator_type
	get_allocator()
	const
	{ return allocator_type(); }

	
};	// class map
	
	/******************************
		  operators overload
	******************************/

	template <class _Key, class _T, class _Compare, class _Allocator>
	bool
	operator==(const map<_Key, _T, _Compare, _Allocator>& lhs,
			   const map<_Key, _T, _Compare, _Allocator>& rhs)
	{ return lhs._RBTree == rhs._RBTree; }

	template <class _Key, class _T, class _Compare, class _Allocator>
	bool
	operator<(const map<_Key, _T, _Compare, _Allocator>& lhs,
			  const map<_Key, _T, _Compare, _Allocator>& rhs)
	{ return lhs._RBTree < rhs._RBTree; }

	template <class _Key, class _T, class _Compare, class _Allocator>
	bool
	operator!=(const map<_Key, _T, _Compare, _Allocator>& lhs,
			   const map<_Key, _T, _Compare, _Allocator>& rhs)
	{ return not (lhs == rhs); }

	template <class _Key, class _T, class _Compare, class _Allocator>
	bool
	operator>(const map<_Key, _T, _Compare, _Allocator>& lhs,
			  const map<_Key, _T, _Compare, _Allocator>& rhs)
	{ return rhs < lhs; }

	template <class _Key, class _T, class _Compare, class _Allocator>
	bool
	operator>=(const map<_Key, _T, _Compare, _Allocator>& lhs,
			   const map<_Key, _T, _Compare, _Allocator>& rhs)
	{ return not (lhs < rhs); }

	template <class _Key, class _T, class _Compare, class _Allocator>
	bool
	operator<=(const map<_Key, _T, _Compare, _Allocator>& lhs,
			   const map<_Key, _T, _Compare, _Allocator>& rhs)
	{ return not (rhs < lhs); }

	/******************************
		specialized algorithm
	******************************/

	template <class _Key, class _T, class _Compare, class _Allocator>
	void
	swap(map<_Key, _T, _Compare, _Allocator>& x, map<_Key, _T, _Compare, _Allocator>& y)
	{ x.swap(y); }

}	//namespace ft

#endif	//MAP_HPP