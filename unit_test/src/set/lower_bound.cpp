/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_bound.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 23:52:07 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_set.hpp"

int main()
{
    NAMESPACE::set<int> set;
	for (int i = 1 ; i < 4242 ; i++)
		set.insert(i);
	std::cout << *set.lower_bound(0) << std::endl;
	std::cout << *set.lower_bound(1) << std::endl;
	std::cout << *set.lower_bound(2) << std::endl;
	std::cout << *set.lower_bound(2121) << std::endl;
	std::cout << *set.lower_bound(4240) << std::endl;
	std::cout << *set.lower_bound(4241) << std::endl;
	return 0;
}
