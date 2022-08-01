/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert(1).cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/29 04:02:26 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_map.hpp"

int main()
{
	NAMESPACE::pair<NAMESPACE::map<int, int>::iterator, bool> ret1;
	NAMESPACE::pair<NAMESPACE::map<char, std::string>::iterator, bool> ret2;
    NAMESPACE::map<int, int> map1;
    NAMESPACE::map<char, std::string> map2;
	ret1 = map1.insert(NAMESPACE::make_pair(1, 42));
	std::cout << (*ret1.first).first << "-" << (*ret1.first).second << " -> " << ret1.second << std::endl;
	ret2 = map2.insert(NAMESPACE::make_pair('a', "fourty two"));
	std::cout << (*ret2.first).first << "-" << (*ret2.first).second << " -> " << ret2.second << std::endl;
	ft::printMap(map1);
	ft::printMap(map2);
	return 0;
}
