/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator=.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/29 08:06:01 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_map.hpp"

int main()
{
	NAMESPACE::map<int, int> map;
	for (int i = 1 ; i < 4242 ; i++)
		map.insert(NAMESPACE::make_pair(i, i + 42));
	NAMESPACE::map<int, int> mapCpy;
	mapCpy = map;
	ft::printMap(map);
	ft::printMap(mapCpy);
	return 0;
}
