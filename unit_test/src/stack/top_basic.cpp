/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_basic.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 03:13:14 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/16 23:34:47 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int main()
{
    NAMESPACE::stack<int> stack;
    for (int i = 0 ; i < 4242 ; i++)
        stack.push(i);
    std::cout << stack.top() << std::endl;
    return 0;
}