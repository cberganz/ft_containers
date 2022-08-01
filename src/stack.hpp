/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:50:54 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 15:57:11 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{

template <class T, class Container = ft::vector<T> >
class stack {

public:

	typedef typename Container::value_type	value_type;
	typedef typename Container::size_type	size_type;
	typedef Container						container_type;

protected:

	container_type _M_container;

public:
	
	explicit
	stack(const Container & container = Container())
		: _M_container(container)
	{}

	bool
	empty()
	const
	{ return _M_container.empty(); }

	size_type
	size()
	const
	{ return _M_container.size(); }

	value_type &
	top()
	{ return _M_container.back(); }

	const
	value_type &
	top()
	const
	{ return _M_container.back(); }

	void
	push(const value_type &x)
	{ _M_container.push_back(x); }

	void
	pop()
	{ _M_container.pop_back(); }

	template <class _T, class __Container>
	friend
	bool
	operator==(const stack<_T, __Container> &x,
			   const stack<_T, __Container> &y);

	template <class _T, class __Container>
	friend
	bool
	operator<(const stack<_T, __Container> &x,
			  const stack<_T, __Container> &y);

	template <class _T, class __Container>
	friend
	bool
	operator!=(const stack<_T, __Container> &x,
			   const stack<_T, __Container> &y);

	template <class _T, class __Container>
	friend
	bool
	operator>(const stack<_T, __Container> &x,
			  const stack<_T, __Container> &y);

	template <class _T, class __Container>
	friend
	bool
	operator>=(const stack<_T, __Container> &x,
			   const stack<_T, __Container> &y);

	template <class _T, class __Container>
	friend
	bool
	operator<=(const stack<_T, __Container> &x,
			   const stack<_T, __Container> &y);

}; // class stack

template <class _T, class _Container>
bool
operator==(const ft::stack<_T, _Container>& lhs,
		   const ft::stack<_T, _Container>& rhs)
{ return lhs._M_container == rhs._M_container; }

template <class _T, class _Container>
bool operator!=(const ft::stack<_T, _Container>& lhs,
				const ft::stack<_T, _Container>& rhs)
{ return lhs._M_container != rhs._M_container; }

template <class _T, class _Container>
bool
operator<(const ft::stack<_T, _Container>& lhs,
		  const ft::stack<_T, _Container>& rhs)
{ return lhs._M_container < rhs._M_container; }

template <class _T, class _Container>
bool
operator<=(const ft::stack<_T, _Container>& lhs,
		   const ft::stack<_T, _Container>& rhs)
{ return lhs._M_container <= rhs._M_container; }	
	
template <class _T, class _Container>
bool
operator>(const ft::stack<_T, _Container>& lhs,
		  const ft::stack<_T, _Container>& rhs)
{ return lhs._M_container > rhs._M_container; }

template <class _T, class _Container>
bool
operator>=(const ft::stack<_T, _Container>& lhs,
		   const ft::stack<_T, _Container>& rhs)
{ return lhs._M_container >= rhs._M_container; }	

} // namespace ft

#endif