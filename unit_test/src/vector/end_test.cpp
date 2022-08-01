/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 05:40:26 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/15 22:04:43 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int main()
{
    NAMESPACE::vector<int> vector;
    for (int i = 0 ; i < 4242 ; i++)
        vector.push_back(i);
    std::cout << *(vector.end() - 21) << std::endl;
    std::cout << *(vector.end() - 42) << std::endl;
    return 0;
}