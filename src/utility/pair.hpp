/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:59:02 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 09:28:34 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

template<class T1, class T2>
struct pair {
	
	typedef T1 first_type;
	typedef T2 second_type;
		
	T1 first;
	T2 second;
		
	pair()
		: first(), second()
	{}
		
	pair(const T1 &x, const T2 &y)
		: first(x), second(y)
	{}
		
	template<class InputT1, class InputT2>
	pair(const pair<InputT1, InputT2> &other)
		: first(other.first),
		  second(other.second)
	{}
	
};	// struct pair
	
template<class T1, class T2>
inline bool
operator==(const pair<T1, T2> &rhs,
		   const pair<T1, T2> &lhs)
{ return rhs.first == lhs.first and rhs.second == lhs.second; }
	
template<class T1, class T2>
inline bool
operator<(const pair<T1, T2> &rhs,
		  const pair<T1, T2> &lhs)
{
	return rhs.first < lhs.first
         or (not (rhs.first > lhs.first)
		 and rhs.second < lhs.second);
}
	
template<class T1, class T2>
inline bool
operator!=(const pair<T1, T2> &rhs,
		   const pair<T1, T2> &lhs)
{ return not (rhs == lhs); }
	
template<class T1, class T2>
inline bool
operator>(const pair<T1, T2> &rhs,
		  const pair<T1, T2> &lhs)
{ return lhs < rhs; }
	
template<class T1, class T2>
inline bool
operator<=(const pair<T1, T2> &rhs,
		   const pair<T1, T2> &lhs)
{ return not (lhs < rhs); }
	
template<class T1, class T2>
inline bool
operator>=(const pair<T1, T2> &rhs,
		   const pair<T1, T2> &lhs)
{ return not (rhs < lhs); }
	
template <class T1,class T2>
pair<T1,T2> make_pair(T1 x, T2 y)
{ return pair<T1,T2>(x,y); }

}	// namespace ft

#endif	// PAIR_HPP