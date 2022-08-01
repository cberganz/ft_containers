/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:30:55 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/16 23:51:45 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int main()
{
    NAMESPACE::stack<int> stack;
    for (int i = 0 ; i < 4242 ; i++)
        stack.push(i);
    for (int i = 0 ; i < 42 ; i++)
        stack.pop();
    ft::printStack(stack);
    return 0;
}