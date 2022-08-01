/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_hard.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:06:36 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/15 12:08:57 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

void    checkErase(NAMESPACE::vector<std::string> const &vct,
                                        NAMESPACE::vector<std::string>::const_iterator const &it)
{
        static int i = 0;
        std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
    	ft::printValues(vct);
}

int             main(void)
{
        NAMESPACE::vector<std::string> vct(10);

        for (unsigned long int i = 0; i < vct.size(); ++i)
                vct[i] = std::string((vct.size() - i), i + 65);
    	ft::printValues(vct);

        checkErase(vct, vct.erase(vct.begin() + 2));

        checkErase(vct, vct.erase(vct.begin()));
        checkErase(vct, vct.erase(vct.end() - 1));

        checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
        checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

        vct.push_back("Hello");
        vct.push_back("Hi there");
    	ft::printValues(vct);
        checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

        vct.push_back("ONE");
        vct.push_back("TWO");
        vct.push_back("THREE");
        vct.push_back("FOUR");
    	ft::printValues(vct);
        checkErase(vct, vct.erase(vct.begin(), vct.end()));

        return (0);
}