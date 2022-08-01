/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor_iterators.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 05:31:19 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/15 22:04:19 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int main()
{
    std::vector<int> tmp(4242, 42);
	NAMESPACE::vector<int> vector(tmp.begin(), tmp.end());
    ft::printValues(vector);
	return 0;
}