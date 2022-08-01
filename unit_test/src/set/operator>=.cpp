/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator>=.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 23:51:29 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_set.hpp"

int main()
{
	NAMESPACE::set<int> set1;
	for (int i = 1 ; i < 4242 ; i++)
		set1.insert(i);
	NAMESPACE::set<int> set2;
	for (int i = 1 ; i < 4242 ; i++)
		set2.insert(i);
	std::cout << (set1 >= set2) << std::endl;
	set2.insert(4242);
	std::cout << (set1 >= set2) << std::endl;
	set1.insert(4242);
	set1.insert(4243);
	std::cout << (set1 >= set2) << std::endl;
	return 0;
}
