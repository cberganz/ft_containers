/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert(2).cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 23:01:41 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_set.hpp"

int main()
{
	NAMESPACE::set<int>::iterator ret1;
	NAMESPACE::set<std::string>::iterator ret2;
    NAMESPACE::set<int> set1;
    NAMESPACE::set<std::string> set2;
	ret1 = set1.insert(set1.begin(), 42);
	std::cout << *ret1 << std::endl;
	ret2 = set2.insert(set2.begin(), "fourty two");
	std::cout << *ret2 << std::endl;
	ft::printSet(set1);
	ft::printSet(set2);
	return 0;
}
