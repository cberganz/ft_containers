/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_basic.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/29 06:27:38 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_map.hpp"
#include <vector>

int main()
{
	NAMESPACE::map<int, int> map;
	map.insert(NAMESPACE::make_pair(42, 4242));
	std::cout << map.count(21) << std::endl;
	std::cout << map.count(42) << std::endl;
	map.insert(NAMESPACE::make_pair(21, 2121));
	map.insert(NAMESPACE::make_pair(42, 4242));
	std::cout << map.count(21) << std::endl;
	std::cout << map.count(42) << std::endl;
	return 0;
}
