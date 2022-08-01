/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:33:13 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/16 23:51:58 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int main()
{
    NAMESPACE::stack<int> stack;
    stack.push(42);
    ft::printStack(stack);
    return 0;
}