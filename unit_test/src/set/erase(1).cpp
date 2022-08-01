/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase(1).cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 22:18:30 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_set.hpp"
#include <vector>

int main()
{
	std::vector<int> vec;
	for (int i = 1 ; i <= 42 ; i++)
		vec.push_back(i);
	NAMESPACE::set<int> set;
	set.insert(vec.begin(), vec.end());
	for (int i = 2 ; i <= 41 ; i++)
		std::cout << set.erase(i) << std::endl;
	ft::printSet(set);
	return 0;
}
