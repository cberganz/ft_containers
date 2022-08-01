/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctor_size.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:29:21 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/15 15:32:50 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int	main()
{
    {
        NAMESPACE::vector<int> v(64, 1);
    	ft::printValues(v);
    }
    {
        NAMESPACE::vector<int> v(0, -1);
    	ft::printValues(v);
    }
    {
        NAMESPACE::vector<std::string> v(26, "");
    	ft::printValues(v);
    }
    {
        NAMESPACE::vector<std::string> v(0, "THERE YOU ARE !");
    	ft::printValues(v);
    }
	return 0;
}