/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase(3).cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/28 21:41:08 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_map.hpp"
#include <vector>

int main()
{
	std::vector<NAMESPACE::pair<int, int> > vec;
	for (int i = 1 ; i < 4242 ; i++)
		vec.push_back(NAMESPACE::make_pair(i, i + 42));
	NAMESPACE::map<int, int> map;
	map.insert(vec.begin(), vec.end());
	NAMESPACE::map<int, int>::iterator it1 = map.find(42);
	NAMESPACE::map<int, int>::iterator it2 = map.find(43);
	map.erase(it1, it2);
	ft::printMap(map);
	return 0;
}
