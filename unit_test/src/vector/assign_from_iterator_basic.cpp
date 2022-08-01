/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_from_iterator_basic.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 21:50:07 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/15 22:03:11 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"
#include <vector>

int main()
{
	NAMESPACE::vector<int> vector;
	std::vector<int> tmp;
	tmp.assign(4242, 42);
	vector.assign(tmp.begin(), tmp.end());
    ft::printValues(vector);
	return 0;
}