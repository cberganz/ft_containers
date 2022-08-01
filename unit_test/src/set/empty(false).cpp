/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty(false).cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 22:12:09 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test_set.hpp"

int main()
{
    NAMESPACE::set<int> set;
	set.insert(42);
	std::cout << set.empty() << std::endl;
	return 0;
}
