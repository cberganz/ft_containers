/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_value.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 06:03:30 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/15 22:06:12 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int main()
{
    NAMESPACE::vector<int> vector;
    vector.assign(42, 42);
    ft::printValues(vector);
    std::cout << *(vector.insert(vector.end() - 21, 21)) << std::endl;
    ft::printValues(vector);
    return 0;
}