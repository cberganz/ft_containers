/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_basic.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 04:43:22 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_map.hpp"
#include <vector>

int main()
{
	NAMESPACE::map<int, int> map;
	for (int i = 1 ; i <= 10000 ; i++)
		map.insert(NAMESPACE::make_pair(i, i + 42));
	std::cout << map.find(9999)->first << map.find(9999)->second << std::endl;
	ft::printMap(map);
	return 0;
}
