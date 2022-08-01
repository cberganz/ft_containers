/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase(1).cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/29 01:16:17 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_map.hpp"
#include <vector>

int main()
{
	std::vector<NAMESPACE::pair<int, int> > vec;
	for (int i = 1 ; i <= 42 ; i++)
		vec.push_back(NAMESPACE::make_pair(i, i + 42));
	NAMESPACE::map<int, int> map;
	map.insert(vec.begin(), vec.end());
	for (int i = 2 ; i <= 41 ; i++)
		std::cout << map.erase(i) << std::endl;
	ft::printMap(map);
	return 0;
}
