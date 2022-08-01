/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbegin_basic.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 23:15:22 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_set.hpp"

int main()
{
    NAMESPACE::set<int> set;
	for (int i = 1 ; i < 4242 ; i++)
		set.insert(i);
	NAMESPACE::set<int, int>::reverse_iterator it = set.rbegin();
	it++;
	std::cout << *it << std::endl;
	return 0;
}
