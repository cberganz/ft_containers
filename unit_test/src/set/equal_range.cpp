/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_range.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 22:17:32 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_set.hpp"
#include <vector>
#include <string>

int main()
{
	std::vector<int> vec;
	for (int i = 1 ; i <= 4242 ; i++)
		vec.push_back(i);
	NAMESPACE::set<int> map(vec.begin(), vec.end());
	std::cout << *map.equal_range(0).first << std::endl;
	std::cout << *map.equal_range(0).second << std::endl;
	std::cout << *map.equal_range(1).first << std::endl;
	std::cout << *map.equal_range(1).second << std::endl;
	std::cout << *map.equal_range(2).first << std::endl;
	std::cout << *map.equal_range(2).second << std::endl;
	std::cout << *map.equal_range(2121).first << std::endl;
	std::cout << *map.equal_range(2121).second << std::endl;
	std::cout << *map.equal_range(4240).first << std::endl;
	std::cout << *map.equal_range(4240).second << std::endl;
	std::cout << *map.equal_range(4241).first << std::endl;
	std::cout << *map.equal_range(4241).second << std::endl;
	return 0;
}
