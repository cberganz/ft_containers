/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_basic.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:42:44 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/15 22:02:46 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int main()
{
    NAMESPACE::vector<int> vector;
    vector.assign(4242, 42);
    NAMESPACE::vector<int> tmp(500, 5), tmp2(1000, 10), tmp3(1500, 15);
    long *adr1 = reinterpret_cast<long *>(&vector);
    long *adr2 = reinterpret_cast<long *>(&tmp);
    vector.swap(tmp);
    if (reinterpret_cast<long *>(&vector) == adr1 && reinterpret_cast<long *>(&tmp) == adr2)
    	std::cout << "Addresses are the same." << std::endl;
    ft::printValues(vector);
    ft::printValues(tmp);
    NAMESPACE::swap(vector, tmp2);
    ft::printValues(vector);
    ft::printValues(tmp2);
    NAMESPACE::swap(vector, tmp3);
    ft::printValues(vector);
    ft::printValues(tmp3);
    return 0;
}