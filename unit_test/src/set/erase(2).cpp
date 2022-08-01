/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase(2).cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/08/01 00:41:10 by cberganz         ###   ########.fr       */
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
	NAMESPACE::set<int>::iterator it = set.find(42);
	set.erase(it);
	ft::printSet(set);
	return 0;
}
