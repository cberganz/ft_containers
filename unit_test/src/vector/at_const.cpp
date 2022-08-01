/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_const.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:28:35 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/15 11:50:33 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int             main(void)
{
        NAMESPACE::vector<int> vector(42);

        for (unsigned long int i = 0; i < vector.size(); ++i)
                vector.at(i) = (vector.size() - i) * 3;
    	ft::printValues(vector);

        NAMESPACE::vector<int> const vector_c(vector);
        std::cout << "front(): " << vector.front() << " " << vector_c.front() << std::endl;
        std::cout << "back(): " << vector.back() << " " <<  vector_c.back() << std::endl;

        for (unsigned long int i = 0; i < vector_c.size(); ++i)
                std::cout << "vector_c.at(): " << vector_c.at(i) << std::endl;
        try {
                std::cout << vector_c.at(10) << std::endl;
        }
        catch (std::out_of_range &e) {
                std::cout << "Catch out_of_range exception!" << std::endl;
        }
        catch (std::exception &e) {
                std::cout << "Catch exception: " << e.what() << std::endl;
        }
    	ft::printValues(vector);
        return (0);
}