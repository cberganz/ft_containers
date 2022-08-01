/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_basic.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 22:14:49 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_set.hpp"

int main()
{
    NAMESPACE::set<int> set;
	for (int i = 1 ; i < 4242 ; i++)
		set.insert(i);
	NAMESPACE::set<int>::iterator it = set.end();
	it--;
	std::cout << *it << std::endl;
	return 0;
}
