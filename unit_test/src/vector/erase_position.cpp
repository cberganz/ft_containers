/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_position.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 05:52:03 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/15 22:04:54 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int main()
{
    NAMESPACE::vector<int> vector;
    for (int i = 0; i < 9900; ++i)
        vector.push_back(i);
    std::cout << *(vector.erase(vector.begin() + 42)) << std::endl;
    ft::printValues(vector);
    return 0;
}