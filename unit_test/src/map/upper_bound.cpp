/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_bound.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/29 07:20:34 by cberganz         ###   ########.fr       */
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
	NAMESPACE::map<int, int> map(vec.begin(), vec.end());
	std::cout << (*map.upper_bound(0)).first << std::endl;
	std::cout << (*map.upper_bound(1)).first << std::endl;
	std::cout << (*map.upper_bound(2)).first << std::endl;
	std::cout << (*map.upper_bound(2121)).first << std::endl;
	std::cout << (*map.upper_bound(4240)).first << std::endl;
	std::cout << (*map.upper_bound(4241)).first << std::endl;
	return 0;
}
