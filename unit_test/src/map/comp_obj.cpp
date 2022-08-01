/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_obj.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 09:48:27 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/30 14:16:46 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_map.hpp"

#define T1 char
#define T2 float
typedef NAMESPACE::map<T1, T2> _map;
typedef _map::const_iterator const_it;

static unsigned int i = 0;

void	ft_comp(const _map &mp, const const_it &it1, const const_it &it2)
{
	bool res[2];

	std::cout << "\t-- [" << ++i << "] --" << std::endl;
	res[0] = mp.key_comp()(it1->first, it2->first);
	res[1] = mp.value_comp()(*it1, *it2);
	std::cout << "with [" << it1->first << " and " << it2->first << "]: ";
	std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
}

int		main(void)
{
	_map	map;

	map['a'] = 2.3;
	map['b'] = 1.4;
	map['c'] = 0.3;
	map['d'] = 4.2;
	ft::printMap(map);

	for (const_it it1 = map.begin(); it1 != map.end(); ++it1)
		for (const_it it2 = map.begin(); it2 != map.end(); ++it2)
			ft_comp(map, it1, it2);
	ft::printMap(map);
	return (0);
}
