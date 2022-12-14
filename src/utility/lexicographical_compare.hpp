/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:10:23 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 08:20:20 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft
{

template <class InputIt1, class InputIt2>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
							 InputIt2 first2, InputIt2 last2)
{
	while (first1 != last1)
	{
		if (first2 == last2)
			return false;
		if (*first1 < *first2)
			return true;
		if (*first2 < *first1)
			return false;
		++first1;
		++first2;
	}
	return not (first2 == last2);
}

template <class InputIt1, class InputIt2, class Compare>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
							 InputIt2 first2, InputIt2 last2,
							 Compare comp)
{
	while (first1 != last1)
	{
		if (first2 == last2)
			return false;
		if (comp(*first1, *first2))
			return true;
		if (comp(*first2, *first1))
			return false;
		++first1;
		++first2;
	}
	return not (first2 == last2);
}

}	// namespace ft

#endif	// LEXICOGRAPHICAL_COMPARE_HPP