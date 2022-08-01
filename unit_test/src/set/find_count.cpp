/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_count.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:19:05 by cberganz          #+#    #+#             */
/*   Updated: 2022/08/01 00:41:07 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_set.hpp"

#define T1 std::string

NAMESPACE::set<T1> set;
NAMESPACE::set<T1>::iterator it = set.end();

void	ft_find(T1 const &k)
{
	NAMESPACE::set<T1>::iterator ret = set.find(k);

	if (ret != it)
		std::cout << *ret << " | " << *ret << std::endl;
	else
		std::cout << "map::find(" << k << ") returned end()" << std::endl;
}

void	ft_count(T1 const &k)
{
	std::cout << "map::count(" << k << ")\treturned [" << set.count(k) << "]" << std::endl;
}

int		main(void)
{
	set.insert("fgzgxfn");
	set.insert("funny");
	set.insert("hey");
	set.insert("no");
	set.insert("bee");
	set.insert("8");
	ft::printSet(set);

	std::cout << "\t-- FIND --" << std::endl;
	ft_find("truc");
	ft_find("funny");
	ft_find("bee");
	ft_find("");
	ft_find("8");

	std::cout << "\t-- COUNT --" << std::endl;
	ft_count("truc");
	ft_count("funny");
	ft_count("bee");
	ft_count("");
	ft_count("8");

	ft::printSet(set);

	NAMESPACE::set<T1> const setCpy(set.begin(), set.end());
	std::cout << "const set.find(8): [" << *setCpy.find("8") << "]" << std::endl;
	std::cout << "const set.count(bee): [" << setCpy.count("bee") << "]" << std::endl;
	return (0);
}
