/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_basic.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:38:55 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/15 22:08:22 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int main()
{
    NAMESPACE::vector<int> vector;
    vector.assign(4242, 1);
    vector.resize(5000);
    std::cout << vector.size() << std::endl;
    std::cout << vector.capacity() << std::endl;
    vector.reserve(5000);
    std::cout << vector.size() << std::endl;
    std::cout << vector.capacity() << std::endl;
    vector.resize(42);
    std::cout << vector.size() << std::endl;
    std::cout << vector.capacity() << std::endl;
    vector.resize(42000);
    std::cout << vector.size() << std::endl;
    std::cout << vector.capacity() << std::endl;
    return 0;
}