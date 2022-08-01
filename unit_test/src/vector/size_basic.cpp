/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_basic.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:41:36 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/15 22:08:33 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int main()
{
    NAMESPACE::vector<int> vector;
    vector.assign(42421, 42);
    std::cout << vector.size() << std::endl;
    return 0;
}