/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_hard.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:09:51 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/15 22:05:40 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int             main(void)
{
        NAMESPACE::vector<int> vct(5);
        NAMESPACE::vector<int> vct2;
        const int cut = 3;

        for (unsigned long int i = 0; i < vct.size(); ++i)
                vct[i] = (vct.size() - i) * 7;
    	ft::printValues(vct);

        vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
    	ft::printValues(vct2);
        vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
    	ft::printValues(vct2);
        vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
    	ft::printValues(vct2);

        std::cout << "insert return:" << std::endl;

        std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
        std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;

    	ft::printValues(vct2);
        return (0);
}