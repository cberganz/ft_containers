/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert(3).cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 23:02:36 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_set.hpp"
#include <vector>

int main()
{
	std::vector<int> vec;
	for (int i = 1 ; i < 4242 ; i++)
		vec.push_back(i);
	NAMESPACE::set<int> set;
	set.insert(vec.begin(), vec.end());
	ft::printSet(set);
	return 0;
}
