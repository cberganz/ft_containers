/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_double.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 22:44:57 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_set.hpp"

int main()
{
	NAMESPACE::pair<NAMESPACE::set<int>::iterator, bool> ret;
    NAMESPACE::set<int> set1;
	ret = set1.insert(42);
	std::cout << *ret.first << " -> " << ret.second << std::endl;
	ret = set1.insert(4242);
	std::cout << *ret.first << " -> " << ret.second << std::endl;
	ft::printSet(set1);
	return 0;
}
