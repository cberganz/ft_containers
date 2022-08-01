/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_range_const.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/29 07:26:00 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_map.hpp"
#include <vector>
#include <string>

int main()
{
	std::vector<NAMESPACE::pair<int, int> > vec;
	for (int i = 1 ; i <= 4242 ; i++)
		vec.push_back(NAMESPACE::make_pair(i, i + 42));
	NAMESPACE::map<int, int> const map(vec.begin(), vec.end());
	std::cout << (*map.equal_range(0).first).first << std::endl;
	std::cout << (*map.equal_range(0).first).second << std::endl;
	std::cout << (*map.equal_range(1).first).first << std::endl;
	std::cout << (*map.equal_range(1).first).second << std::endl;
	std::cout << (*map.equal_range(2).first).first << std::endl;
	std::cout << (*map.equal_range(2).first).second << std::endl;
	std::cout << (*map.equal_range(2121).first).first << std::endl;
	std::cout << (*map.equal_range(2121).first).second << std::endl;
	std::cout << (*map.equal_range(4240).first).first << std::endl;
	std::cout << (*map.equal_range(4240).first).second << std::endl;
	std::cout << (*map.equal_range(4241).first).first << std::endl;
	std::cout << (*map.equal_range(4241).first).second << std::endl;
	return 0;
}
