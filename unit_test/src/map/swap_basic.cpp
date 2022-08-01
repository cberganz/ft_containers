/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/29 06:08:05 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_map.hpp"

int main()
{
    NAMESPACE::map<int, int> map1;
    NAMESPACE::map<int, int> map2;
	for (int i = 0 ; i < 4242 ; i++)
		map1.insert(NAMESPACE::make_pair(i, i + 42));
	for (int i = 4242 ; i < 8484 ; i++)
		map2.insert(NAMESPACE::make_pair(i, i + 42));
	map1.swap(map2);
	ft::printMap(map1);
	ft::printMap(map2);
	return 0;
}
