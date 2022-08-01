/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_basic.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 22:11:35 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_set.hpp"

int main()
{
	NAMESPACE::set<int> set;
	set.insert(21);
	std::cout << set.count(21) << std::endl;
	std::cout << set.count(42) << std::endl;
	set.insert(42);
	set.insert(21);
	std::cout << set.count(21) << std::endl;
	std::cout << set.count(42) << std::endl;
	return 0;
}
