/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 06:05:16 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/15 22:06:24 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int main()
{
    NAMESPACE::vector<int> vector;
    NAMESPACE::vector<int>::iterator it;
    for (int i = 0; i < 10; ++i)
        vector.push_back(i);
    it = vector.begin();
    std::cout << *(++it) << std::endl;
    std::cout << *(it - 1) << std::endl;
    std::cout << *(--it) << std::endl;
    std::cout << *(it + 1) << std::endl;
    it += 1;
    std::cout << *it << std::endl;
    it -= 1;
    std::cout << *it << std::endl;
    return 0;
}