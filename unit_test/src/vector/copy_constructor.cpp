/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_constructor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:52:41 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/15 11:57:59 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int             main(void)
{
        NAMESPACE::vector<int> vct(5);
        NAMESPACE::vector<int>::iterator it = vct.begin(), ite = vct.end();

        std::cout << "len: " << (ite - it) << std::endl;
        for (; it != ite; ++it) {
                *it = (ite - it); }
        it = vct.begin();
        NAMESPACE::vector<int> vct_range(it, --(--ite));
        for (int i = 0; it != ite; ++it)
                *it = ++i * 5;

        it = vct.begin();
        NAMESPACE::vector<int> vct_copy(vct);
        for (int i = 0; it != ite; ++it)
                *it = ++i * 7;
        vct_copy.push_back(42);
        vct_copy.push_back(21);

        std::cout << "\t-- PART ONE --" << std::endl;
    	ft::printValues(vct);
    	ft::printValues(vct_range);
    	ft::printValues(vct_copy);

        vct = vct_copy;
        vct_copy = vct_range;
        vct_range.clear();

        std::cout << "\t-- PART TWO --" << std::endl;
    	ft::printValues(vct);
    	ft::printValues(vct_range);
    	ft::printValues(vct_copy);
        return (0);
}