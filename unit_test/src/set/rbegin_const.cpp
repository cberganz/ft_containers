/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbegin_const.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 23:16:27 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_set.hpp"
#include <vector>

int main()
{
	std::vector<int> vec;
	for (int i = 1 ; i <= 4242 ; i++)
		vec.push_back(i);
	NAMESPACE::set<int> const set(vec.begin(), vec.end());
	NAMESPACE::set<int>::const_reverse_iterator it = set.rbegin();
	it++;
	std::cout << *it << std::endl;
	return 0;
}
