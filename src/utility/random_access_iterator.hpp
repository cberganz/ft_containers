/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:02:53 by cberganz          #+#    #+#             */
/*   Updated: 2022/08/01 21:13:19 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator_base.hpp"

namespace ft {
    
template <typename T>
class random_access_iterator : ft::iterator<std::random_access_iterator_tag, T>
{

public:	
    typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;
    typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type			value_type;
    typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
    typedef T *																				pointer;
    typedef T &																				reference;

    random_access_iterator()
    	: current(0)
    {}

    random_access_iterator(pointer ptr)
    	: current(ptr)
    {}

    random_access_iterator(const random_access_iterator &it)
    	: current(it.current)
    {}

    random_access_iterator &
	operator=(const random_access_iterator &rhs)
    {
        if (this == &rhs)
		        return *this;
        this->current = rhs.current;
        return *this;
    }

    virtual
	~random_access_iterator() {}

    pointer
	base()
	const
    { return this->current; }

    reference
	operator*()
	const
	{ return *this->current; }

    pointer
	operator->()
	{ return &(this->operator*()); }

    random_access_iterator &
	operator++()
    {
        this->current++;
        return *this;
    }

    random_access_iterator
	operator++(int)
    {
        random_access_iterator tmp(*this);
        operator++();
        return tmp;
    }

    random_access_iterator &
	operator--()
    {
        this->current--;
        return *this;
    }

    random_access_iterator
	operator--(int)
    {
        random_access_iterator tmp(*this);
        operator--();
        return tmp;
    }

    random_access_iterator
	operator+(difference_type n)
	const
	{ return this->current + n; }

    random_access_iterator
	operator-(difference_type n)
	const
	{ return this->current - n; }

    random_access_iterator &
	operator+=(difference_type n)
    {
        this->current += n;
        return *this;
    }

    random_access_iterator &
	operator-=(difference_type n)
    {
        this->current -= n;
        return *this;
    }

    reference
	operator[](difference_type n)
	{ return *(operator + (n)); }

    operator random_access_iterator<const T>()
	const
    { return random_access_iterator<const T>(this->current); }

private:
    pointer current;

};	// class random_access_iterator

template <typename T>
inline bool
operator==(const ft::random_access_iterator<T> &lhs,
           const ft::random_access_iterator<T> &rhs)
{ return lhs.base() == rhs.base(); }

template<typename T1, typename T2>
inline bool
operator==(const ft::random_access_iterator<T1> &lhs,
           const ft::random_access_iterator<T2> &rhs)
{ return lhs.base() == rhs.base(); }

template <typename T>
inline bool
operator!=(const ft::random_access_iterator<T> &lhs,
           const ft::random_access_iterator<T> &rhs)
{ return lhs.base() != rhs.base(); }

template<typename T1, typename T2>
inline bool
operator!=(const ft::random_access_iterator<T1> &lhs,
           const ft::random_access_iterator<T2> &rhs)
{ return lhs.base() != rhs.base(); }

template <typename T>
inline bool
operator<(const ft::random_access_iterator<T> &lhs,
          const ft::random_access_iterator<T> &rhs)
{ return lhs.base() < rhs.base(); }

template<typename T1, typename T2>
inline bool
operator<(const ft::random_access_iterator<T1> &lhs,
          const ft::random_access_iterator<T2> &rhs)
{ return lhs.base() < rhs.base(); }

template <typename T>
inline bool
operator>(const ft::random_access_iterator<T> &lhs,
          const ft::random_access_iterator<T> &rhs)
{ return lhs.base() > rhs.base(); }

template<typename T1, typename T2>
inline bool
operator>(const ft::random_access_iterator<T1> &lhs,
          const ft::random_access_iterator<T2> &rhs)
{ return lhs.base() > rhs.base(); }

template <typename T>
inline bool
operator<=(const ft::random_access_iterator<T> &lhs,
           const ft::random_access_iterator<T> &rhs)
{ return lhs.base() <= rhs.base(); }

template<typename T1, typename T2>
inline bool
operator<=(const ft::random_access_iterator<T1> &lhs,
           const ft::random_access_iterator<T2> &rhs)
{ return lhs.base() <= rhs.base(); }

template <typename T>
inline bool
operator>=(const ft::random_access_iterator<T> &lhs,
           const ft::random_access_iterator<T> &rhs)
{ return lhs.base() >= rhs.base(); }

template<typename T1, typename T2>
inline bool
operator>=(const ft::random_access_iterator<T1> &lhs,
           const ft::random_access_iterator<T2> &rhs)
{ return lhs.base() >= rhs.base(); }

template<typename T>
inline ft::random_access_iterator<T>
operator+(typename ft::random_access_iterator<T>::difference_type n,
    	  typename ft::random_access_iterator<T> it)
{ return &(*it) + n; }

template <typename T>
inline typename ft::random_access_iterator<T>::difference_type
operator-(const ft::random_access_iterator<T> &lhs,
          const ft::random_access_iterator<T> &rhs)
{ return lhs.base() - rhs.base(); }

template<typename T1, typename T2>
inline typename ft::random_access_iterator<T1>::difference_type
operator-(const ft::random_access_iterator<T1> &lhs,
          const ft::random_access_iterator<T2> &rhs)
{ return lhs.base() - rhs.base(); }

}	// namespace ft

#endif	// RANDOM_ACCESS_ITERATOR_HPP