/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relational_ope.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:21:43 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/16 23:48:36 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

template <class T, class Alloc>
void	cmp(const NAMESPACE::stack<T, Alloc> &lhs, const NAMESPACE::stack<T, Alloc> &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main(void)
{
	NAMESPACE::stack<int> stack;
	NAMESPACE::stack<int> stack2;

	cmp(stack, stack);  // 0
	cmp(stack, stack2); // 1

	stack2.push(0);

	cmp(stack, stack2); // 2
	cmp(stack2, stack); // 3

	stack.push(42);

	cmp(stack, stack2); // 4
	cmp(stack2, stack); // 5

	stack.pop();
	stack2.pop();

	cmp(stack, stack2); // 6
	cmp(stack2, stack); // 7

	return (0);
}
