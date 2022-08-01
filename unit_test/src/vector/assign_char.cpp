/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_char.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:14:13 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/15 22:01:20 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int main()
{
    {
        NAMESPACE::vector<char> v;
        v.assign(0, 'c');
    	ft::printValues(v);
        v.assign(64, 'A');
    	ft::printValues(v);
        v.assign(32, '5');
    	ft::printValues(v);
        v.assign(49, '8');
    	ft::printValues(v);
        v.assign(77, '2');
    	ft::printValues(v);
    }
    {
        NAMESPACE::vector<std::string> v;
        v.assign(0, "");
    	ft::printValues(v);
        v.assign(64, "vector-string");
    	ft::printValues(v);
    }
	return 0;
}