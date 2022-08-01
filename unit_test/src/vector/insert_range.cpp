/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_range.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 05:58:25 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/15 22:06:00 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/unit_test.hpp"

int main()
{
    NAMESPACE::vector<int> vector;
    std::vector<int> tmp;
    tmp.assign(21, 21);
    vector.assign(42, 42);
    vector.insert(vector.end() - 21, tmp.begin(), tmp.end());
    ft::printValues(vector);
    return 0;
}