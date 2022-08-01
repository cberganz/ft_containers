/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_basic.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/29 06:09:52 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_map.hpp"

int main()
{
    NAMESPACE::map<int, int> map;
	for (int i = 0 ; i < 4242 ; i++)
		map.insert(NAMESPACE::make_pair(i, i + 42));
	map.clear();
	ft::printMap(map);
	return 0;
}
