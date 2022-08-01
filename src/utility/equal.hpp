/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:24:35 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 02:42:24 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

# include <cstring>

namespace ft
{

template <typename T>
bool
equal(const T *first1, const T *last1, const T *first2)
{
	if (const size_t len = (last1 - first1))
		return !std::memcmp(first1, first2, len);
	return true;
}

template <typename It1, typename It2>
bool
equal(It1 first1, It1 last1, It2 first2)
{
	for (; first1 != last1 ; ++first1, ++first2)
		if (not (*first1 == *first2))
			return false;
	return true;
}

}	// namespace ft

#endif	// EQUAL_HPP