/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert(1).cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 22:59:48 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_set.hpp"

int main()
{
	NAMESPACE::pair<NAMESPACE::set<int>::iterator, bool> ret1;
	NAMESPACE::pair<NAMESPACE::set<std::string>::iterator, bool> ret2;
    NAMESPACE::set<int> set1;
    NAMESPACE::set<std::string> set2;
	ret1 = set1.insert(42);
	std::cout << *ret1.first << " -> " << ret1.second << std::endl;
	ret2 = set2.insert("fourty two");
	std::cout << *ret2.first << " -> " << ret2.second << std::endl;
	ft::printSet(set1);
	ft::printSet(set2);
	return 0;
}
