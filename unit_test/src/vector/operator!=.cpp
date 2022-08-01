/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator!=.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 06:11:05 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/15 22:06:42 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int main()
{
    NAMESPACE::vector<int> v_int1, v_int2, v_int3;
    NAMESPACE::vector<std::string> v_str1, v_str2;
    v_int1.push_back(1);
    v_int3.push_back(1);
    v_str1.push_back("aa");
    v_str2.push_back("ab");
    std::cout << (v_int1 != v_int2) << std::endl;
    v_int2.push_back(1);
    std::cout << (v_int1 != v_int2) << std::endl;
    std::cout << (v_int1 != v_int3) << std::endl;
    std::cout << (v_str1 != v_str2) << std::endl;
    return 0;
}