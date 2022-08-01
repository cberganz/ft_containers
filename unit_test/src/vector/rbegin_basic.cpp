/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbegin_basic.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:34:55 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/15 22:07:55 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int main()
{
    NAMESPACE::vector<int> vector;
    for (int i = 0 ; i < 4242 ; i++)
        vector.push_back(i);
    std::cout << *vector.rbegin() << std::endl;
    std::cout << *(vector.rbegin() + 1) << std::endl;
    return 0;
}