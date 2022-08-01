/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_double.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/29 04:02:22 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_map.hpp"

int main()
{
	NAMESPACE::pair<NAMESPACE::map<int, int>::iterator, bool> ret;
    NAMESPACE::map<int, int> map1;
	ret = map1.insert(NAMESPACE::make_pair(1, 42));
	std::cout << (*ret.first).first << "-" << (*ret.first).second << " -> " << ret.second << std::endl;
	ret = map1.insert(NAMESPACE::make_pair(1, 4242));
	std::cout << (*ret.first).first << "-" << (*ret.first).second << " -> " << ret.second << std::endl;
	ft::printMap(map1);
	return 0;
}
