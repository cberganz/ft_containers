/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:49:32 by cberganz          #+#    #+#             */
/*   Updated: 2022/08/01 03:02:07 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include <algorithm>
# include <iostream>
# include <functional>
# include <memory>
# include "RBTree.hpp"
# include "utility/pair.hpp"
# include "utility/reverse_iterator.hpp"
# include "utility/is_integral.hpp"

namespace ft {

template <class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
class set {

	public:
	typedef T														key_type;
	typedef T														value_type;
	typedef Compare													key_compare;
	typedef Compare													value_compare;

	private:
	struct KeyOfValue : public std::unary_function<T, T> {
	
		friend class set<T, Compare, Allocator>;
	
		T &
		operator()(T & x)
		const
		{ return x; }
	
		const T &
		operator()(const T & x)
		const
		{ return x; }	
	
	};	// struct getKeyOfValue

	typedef ft::RBTree<key_type, KeyOfValue, value_type, value_compare, Allocator>		RBTree;
	
	public:
	typedef typename RBTree::allocator_type				allocator_type;
	typedef typename RBTree::reference					reference;
	typedef typename RBTree::const_reference			const_reference;
	typedef typename RBTree::size_type					size_type;
	typedef typename RBTree::pointer					pointer;
	typedef typename RBTree::const_pointer				const_pointer;
	typedef typename RBTree::const_iterator				iterator;
	typedef typename RBTree::const_iterator				const_iterator;
	typedef typename RBTree::const_reverse_iterator		reverse_iterator;
	typedef typename RBTree::const_reverse_iterator		const_reverse_iterator;
	typedef typename RBTree::difference_type			difference_type;

	protected:
	RBTree			_RBTree;

	public:
	explicit
	set(const key_compare& _compare = Compare(), const allocator_type& _allocator = Allocator())
		: _RBTree(_compare, _allocator)
	{}

	template <class InputIterator>
	set(InputIterator first, InputIterator last,
		const Compare& _compare = Compare(), const Allocator& _allocator = Allocator())
		: _RBTree(first, last, _compare, _allocator)
	{}

	set(const set<T, Compare, Allocator>& src)
		: _RBTree(src.begin(), src.end(), src.value_comp(), src._RBTree.get_allocator())
	{}

	~set()
	{ clear(); }

	set<T, Compare, Allocator> &
	operator=(const set<T, Compare, Allocator> &rhs)
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
				modifiers
	******************************/

	ft::pair<iterator, bool>
	insert(const value_type& x)
	{ return _RBTree.insert(x); }

	iterator
	insert(const_iterator position, const value_type& x)
	{ return _RBTree.insert(position, x); }

	template <class InputIterator>
	void
	insert(InputIterator first, InputIterator last)
	{ _RBTree.insert(first, last); }

	size_type
	erase(const value_type& x)
	{ return _RBTree.erase(x); }

	void
	erase(iterator position)
	{ _RBTree.erase(position); }

	void
	erase(iterator first, iterator last)
	{ _RBTree.erase(first, last); }

	void
	swap(set<T, Compare, Allocator> &other)
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
	{ return _RBTree.key_comp(); } // le vrai set renvoi celui de RBT pour les 2

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

	template <class _T, class _Compare, class _Allocator>
	friend
	bool
	operator==(const set<_T, _Compare, _Allocator>& lhs,
			   const set<_T, _Compare, _Allocator>& rhs);

	template <class _T, class _Compare, class _Allocator>
	friend
	bool
	operator<(const set<_T, _Compare, _Allocator>& lhs,
			  const set<_T, _Compare, _Allocator>& rhs);

	/******************************
				allocator
	******************************/

	allocator_type
	get_allocator()
	const
	{ return _RBTree.get_allocator(); }
	
};	// class set
	
	/******************************
		  operators overload
	******************************/

	template <class _T, class _Compare, class _Allocator>
	inline bool
	operator==(const set<_T, _Compare, _Allocator>& lhs,
			   const set<_T, _Compare, _Allocator>& rhs)
	{ return lhs._RBTree == rhs._RBTree; }

	template <class _T, class _Compare, class _Allocator>
	inline bool
	operator<(const set<_T, _Compare, _Allocator>& lhs,
			  const set<_T, _Compare, _Allocator>& rhs)
	{ return lhs._RBTree < rhs._RBTree; }

	template <class _T, class _Compare, class _Allocator>
	inline bool
	operator!=(const set<_T, _Compare, _Allocator>& lhs,
			   const set<_T, _Compare, _Allocator>& rhs)
	{ return not (lhs == rhs); }

	template <class _T, class _Compare, class _Allocator>
	inline bool
	operator>(const set<_T, _Compare, _Allocator>& lhs,
			  const set<_T, _Compare, _Allocator>& rhs)
	{ return rhs < lhs; }

	template <class _T, class _Compare, class _Allocator>
	inline bool
	operator>=(const set<_T, _Compare, _Allocator>& lhs,
			   const set<_T, _Compare, _Allocator>& rhs)
	{ return not (lhs < rhs); }

	template <class _T, class _Compare, class _Allocator>
	inline bool
	operator<=(const set<_T, _Compare, _Allocator>& lhs,
			   const set<_T, _Compare, _Allocator>& rhs)
	{ return not (rhs < lhs); }

	/******************************
		specialized algorithm
	******************************/

	template <class _T, class _Compare, class _Allocator>
	void
	swap(set<_T, _Compare, _Allocator>& x, set<_T, _Compare, _Allocator>& y)
	{ x.swap(y); }

}	//namespace ft

#endif	// SET_HPP