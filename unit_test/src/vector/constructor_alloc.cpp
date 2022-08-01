/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor_alloc.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 05:08:44 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/15 22:04:10 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int main()
{
    NAMESPACE::vector<int> vector(4242, 42);
    try { NAMESPACE::vector<int> tmp(-1, -1); }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }
    ft::printValues(vector);
    return 0;
}