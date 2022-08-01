/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase(3).cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 22:20:46 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_set.hpp"
#include <vector>

int main()
{
	std::vector<int> vec;
	for (int i = 1 ; i < 4242 ; i++)
		vec.push_back(i);
	NAMESPACE::set<int> set;
	set.insert(vec.begin(), vec.end());
	NAMESPACE::set<int>::iterator it1 = set.find(42);
	NAMESPACE::set<int>::iterator it2 = set.find(43);
	set.erase(it1, it2);
	ft::printSet(set);
	return 0;
}
