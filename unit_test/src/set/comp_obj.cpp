/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_obj.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 09:48:27 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 21:57:43 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_set.hpp"

#define T1 float
typedef NAMESPACE::set<T1> set;
typedef NAMESPACE::set<T1>::const_iterator const_it;

static unsigned int i = 0;

void	ft_comp(const set &mp, const const_it &it1, const const_it &it2)
{
	bool res[2];

	std::cout << "\t-- [" << ++i << "] --" << std::endl;
	res[0] = mp.key_comp()(*it1, *it2);
	res[1] = mp.value_comp()(*it1, *it2);
	std::cout << "with [" << *it1 << "]: ";
	std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
}

int		main(void)
{
	set	mySet;

	mySet.insert(2.3);
	mySet.insert(1.4);
	mySet.insert(0.3);
	mySet.insert(4.2);
	ft::printSet(mySet);

	for (const_it it1 = mySet.begin(); it1 != mySet.end(); ++it1)
		for (const_it it2 = mySet.begin(); it2 != mySet.end(); ++it2)
			ft_comp(mySet, it1, it2);
	ft::printSet(mySet);
	return (0);
}
