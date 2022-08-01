/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert(3).cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/29 04:02:40 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_map.hpp"
#include <vector>

int main()
{
	std::vector<NAMESPACE::pair<int, int> > vec;
	for (int i = 1 ; i < 4242 ; i++)
		vec.push_back(NAMESPACE::make_pair(i, i));
	NAMESPACE::map<int, int> map;
	map.insert(vec.begin(), vec.end());
	ft::printMap(map);
	return 0;
}
