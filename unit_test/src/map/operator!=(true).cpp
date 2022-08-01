/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator!=(false) copy 2.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/29 08:52:42 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_map.hpp"

int main()
{
	NAMESPACE::map<int, int> map1;
	for (int i = 1 ; i < 4242 ; i++)
		map1.insert(NAMESPACE::make_pair(i, i + 42));
	NAMESPACE::map<int, int> map2;
	for (int i = 1 ; i < 4242 ; i++)
		map2.insert(NAMESPACE::make_pair(i, i + 42));
	map2.insert(NAMESPACE::make_pair(4242, 4242 + 42));
	std::cout << (map1 != map2) << std::endl;
	return 0;
}
