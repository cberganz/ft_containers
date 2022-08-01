/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_basic.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 22:22:30 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_set.hpp"

int main()
{
	NAMESPACE::set<int> set;
	for (int i = 1 ; i <= 10000 ; i++)
		set.insert(i);
	std::cout << *set.find(9999) << std::endl;
	std::cout << *set.find(500) << std::endl;
	std::cout << *set.find(1) << std::endl;
	ft::printSet(set);
	return 0;
}
