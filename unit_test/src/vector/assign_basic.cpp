/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_basic.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:52:16 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/15 22:02:56 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int main()
{
    NAMESPACE::vector<int> vector;
    vector.assign(4242, 42);
    ft::printValues(vector);
    return 0;
}