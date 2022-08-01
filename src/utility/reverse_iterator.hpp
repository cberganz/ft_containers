/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:51:19 by cberganz          #+#    #+#             */
/*   Updated: 2022/08/01 15:40:14 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_base.hpp"

namespace ft
{

template <typename Iterator>
struct reverse_iterator : public ft::iterator<typename ft::iterator_traits<Iterator>::iterator_category,
							typename ft::iterator_traits<Iterator>::value_type,
							typename ft::iterator_traits<Iterator>::difference_type,
							typename ft::iterator_traits<Iterator>::pointer,
							typename ft::iterator_traits<Iterator>::reference>
{

protected:
	Iterator								current;
	typedef ft::iterator_traits<Iterator>	traits_type;

public:
	typedef Iterator								iterator_type;
	typedef typename traits_type::difference_type	difference_type;
	typedef typename traits_type::pointer			pointer;
	typedef typename traits_type::reference			reference;

	reverse_iterator()
		: current()
	{}

	explicit
	reverse_iterator(iterator_type src)
		: current(src)
	{}

	reverse_iterator(const reverse_iterator &src)
		: current(src.current)
	{}

	template <typename Iterator2>
	reverse_iterator(const reverse_iterator<Iterator2> &src)
		: current(src.base())
	{}

	iterator_type
	base()
	const
	{ return this->current; }

	reference
	operator*()
	const
	{
		Iterator tmp = this->current;
		return *--tmp;
	}

	pointer
	operator->()
	const
	{ return &(operator*()); }

	reverse_iterator &
	operator++()
	{
		--this->current;
		return *this;
	}

	reverse_iterator
	operator++(int)
	{
		reverse_iterator tmp = *this;
		--this->current;
		return tmp;
	}

	reverse_iterator &
	operator--()
	{
		++this->current;
		return *this;
	}

	reverse_iterator
	operator--(int)
	{
		reverse_iterator tmp = *this;
		++this->current;
		return tmp;
	}

	reverse_iterator
	operator+(difference_type n)
	const
	{ return reverse_iterator(this->current - n); }

	reverse_iterator &
	operator+=(difference_type n)
	{
		this->current -= n;
		return *this;
	}

	reverse_iterator
	operator-(difference_type n)
	const
	{ return reverse_iterator(this->current + n); }

	reverse_iterator &
	operator-=(difference_type n)
	{
		this->current += n;
		return *this;
	}

	reference
	operator[](difference_type n)
	const
	{ return *(*this + n); }

};	// struct reverse_iterator

template <typename Iterator>
inline bool
operator==(const reverse_iterator<Iterator> &lhs,
		   const reverse_iterator<Iterator> &rhs)
{ return lhs.base() == rhs.base(); }

template <typename Iterator>
inline bool
operator<(const reverse_iterator<Iterator> &lhs,
		  const reverse_iterator<Iterator> &rhs)
{ return rhs.base() < lhs.base(); }

template <typename Iterator>
inline bool
operator!=(const reverse_iterator<Iterator> &lhs,
		   const reverse_iterator<Iterator> &rhs)
{ return not (lhs == rhs); }

template <typename Iterator>
inline bool
operator>(const reverse_iterator<Iterator> &lhs,
		  const reverse_iterator<Iterator> &rhs)
{ return rhs < lhs; }

template <typename Iterator>
inline bool
operator<=(const reverse_iterator<Iterator> &lhs,
		   const reverse_iterator<Iterator> &rhs)
{ return not (rhs < lhs); }

template <typename Iterator>
inline bool
operator>=(const reverse_iterator<Iterator> &lhs,
		   const reverse_iterator<Iterator> &rhs)
{ return not (lhs < rhs); }

template <typename IteratorL, typename IteratorR>
inline bool
operator==(const reverse_iterator<IteratorL> &lhs,
		   const reverse_iterator<IteratorR> &rhs)
{ return lhs.base() == rhs.base(); }

template <typename IteratorL, typename IteratorR>
inline bool
operator<(const reverse_iterator<IteratorL> &lhs,
		  const reverse_iterator<IteratorR> &rhs)
{ return rhs.base() < lhs.base(); }

template <typename IteratorL, typename IteratorR>
inline bool
operator!=(const reverse_iterator<IteratorL> &lhs,
		   const reverse_iterator<IteratorR> &rhs)
{ return not (lhs == rhs); }

template <typename IteratorL, typename IteratorR>
inline bool
operator>(const reverse_iterator<IteratorL> &lhs,
		  const reverse_iterator<IteratorR> &rhs)
{ return rhs < lhs; }

template <typename IteratorL, typename IteratorR>
inline bool
operator<=(const reverse_iterator<IteratorL> &lhs,
		   const reverse_iterator<IteratorR> &rhs)
{ return not (rhs < lhs); }

template <typename IteratorL, typename IteratorR>
inline bool
operator>=(const reverse_iterator<IteratorL> &lhs,
		   const reverse_iterator<IteratorR> &rhs)
{ return not (lhs < rhs); }

template <typename Iterator>
inline reverse_iterator<Iterator>
operator+(typename reverse_iterator<Iterator>::difference_type n,
		  const reverse_iterator<Iterator> &it)
{ return reverse_iterator<Iterator>(it.base() - n); }

template<typename Iterator1, typename Iterator2>
inline typename reverse_iterator<Iterator1>::difference_type
operator-(const reverse_iterator<Iterator1>& lhs,
		  const reverse_iterator<Iterator2>& rhs)
{ return rhs.base() - lhs.base(); }

} // namespace ft

#endif // REVERSE_ITERATOR_HPP