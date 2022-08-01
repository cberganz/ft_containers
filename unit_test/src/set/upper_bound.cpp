/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_bound.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 23:22:46 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_set.hpp"
#include <vector>
#include <string>

int main()
{
	std::vector<int> vec;
	for (int i = 1 ; i <= 4242 ; i++)
		vec.push_back(i);
	NAMESPACE::set<int> set(vec.begin(), vec.end());
	std::cout << *set.upper_bound(0) << std::endl;
	std::cout << *set.upper_bound(1) << std::endl;
	std::cout << *set.upper_bound(2) << std::endl;
	std::cout << *set.upper_bound(2121) << std::endl;
	std::cout << *set.upper_bound(4240) << std::endl;
	std::cout << *set.upper_bound(4241) << std::endl;
	return 0;
}
