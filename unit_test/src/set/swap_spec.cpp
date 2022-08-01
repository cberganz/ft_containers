/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_spec.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 23:20:29 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_set.hpp"

int main()
{
    NAMESPACE::set<int> set1;
    NAMESPACE::set<int> set2;
	for (int i = 0 ; i < 4242 ; i++)
		set1.insert(i);
	for (int i = 4242 ; i < 8484 ; i++)
		set2.insert(i);
	swap(set1, set2);
	ft::printSet(set1);
	ft::printSet(set2);
	return 0;
}
