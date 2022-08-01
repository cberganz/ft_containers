/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_const.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 22:14:38 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_set.hpp"
#include <vector>

int main()
{
	std::vector<int> vec;
	for (int i = 1 ; i <= 4242 ; i++)
		vec.push_back(i);
	NAMESPACE::set<int> const map(vec.begin(), vec.end());
	NAMESPACE::set<int>::const_iterator it = map.end();
	it--;
	std::cout << *it << std::endl;
	return 0;
}
