/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend_basic.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:36:49 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/18 15:36:41 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int main()
{
    NAMESPACE::vector<int> vector;
    for (int i = 0 ; i < 4242 ; i++)
        vector.push_back(i);
    std::cout << *(vector.rend() - 1) << std::endl;
    std::cout << *(vector.rend() - 2) << std::endl;
    return 0;
}