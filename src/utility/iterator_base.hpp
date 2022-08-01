/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_base.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:52:20 by cberganz          #+#    #+#             */
/*   Updated: 2022/08/01 15:03:02 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_BASE_HPP
# define ITERATOR_BASE_HPP

# include <cstddef>
# include <iterator>

namespace ft
{

template <typename Category, typename T,
		  typename Difference = std::ptrdiff_t,
		  typename Pointer = T*, typename Reference = T&>
struct iterator {

	typedef T			value_type;
	typedef Difference	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;

};

template <typename iterator>
struct iterator_traits {

	typedef typename iterator::difference_type		difference_type;
	typedef typename iterator::value_type			value_type;
	typedef typename iterator::pointer				pointer;
	typedef typename iterator::reference			reference;
	typedef typename iterator::iterator_category	iterator_category;

};

template <typename T>
struct iterator_traits<T *> {

	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef T *								pointer;
	typedef T &								reference;
	typedef std::random_access_iterator_tag	iterator_category;

};

template <typename T>
class iterator_traits<const T *> {

	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef const T *						pointer;
	typedef const T	&						reference;
	typedef std::random_access_iterator_tag	iterator_category;

};

}	// namespace ft

#endif	// ITERATOR_BASE_HPP