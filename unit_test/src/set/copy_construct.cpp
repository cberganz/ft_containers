/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_construct.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 22:01:01 by cberganz          #+#    #+#             */
/*   Updated: 2022/08/01 00:42:54 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "../../include/unit_test_set.hpp"

#define T1 int

int		main(void)
{
	std::vector<T1> vec;
	unsigned int vec_size = 7;
	for (unsigned int i = 0; i < vec_size; ++i)
		vec.push_back(T1(vec_size - i));

	NAMESPACE::set<T1> set(vec.begin(), vec.end());

	NAMESPACE::set<T1>::iterator it = set.begin(), ite = set.end();

	NAMESPACE::set<T1> set_range(it, --(--ite));

	NAMESPACE::set<T1> set_copy(set);

	std::cout << "\t-- PART ONE --" << std::endl;
	ft::printSet(set);
	ft::printSet(set_range);
	ft::printSet(set_copy);

	set = set_copy;
	set_copy = set_range;
	set_range.clear();
	ft::printSet(set);
	ft::printSet(set_range);
	ft::printSet(set_copy);

	return (0);
}
