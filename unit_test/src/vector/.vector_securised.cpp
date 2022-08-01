/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve_basic.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:37:45 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 13:38:27 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"
#include <iomanip>
#include <exception>

struct foo {

	foo()
	{
	}

	foo(const foo &src)
	{
		static int i;
		i++;
		if (i>=8)
			throw std::exception();
		std::cout << "i :" << i << std::endl;
	}

	~foo()
	{
		std::cout << "destructor called" << std::endl;
	}

};

int main()
{
    NAMESPACE::vector<foo> vector;
	vector.reserve(5);
	std::cout << vector.capacity() << std::endl;
	for (int i = 0 ; i < 5; i++)
		vector.push_back(foo());
	std::cout << vector.capacity() << std::endl;
	try
	{
		vector.reserve(20);
	}
	catch (std::exception& e) {}
	std::cout << vector.capacity() << std::endl;
	
    return 0;
}