/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator<=.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:20:59 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/16 23:42:12 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int main()
{
    NAMESPACE::stack<int> int1, int2, int3;
    NAMESPACE::stack<std::string> str1, str2;
    int1.push(1);
    int3.push(1);
    str1.push("aa");
    str2.push("ab");
    std::cout << (int1 <= int2) << std::endl;
    int2.push(2);
    std::cout << (int1 <= int2) << std::endl;
    std::cout << (int1 <= int3) << std::endl;
    std::cout << (str1 <= str2) << std::endl;
    return 0;
}