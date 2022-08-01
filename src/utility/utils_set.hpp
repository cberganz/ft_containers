/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_set.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:35:07 by cberganz          #+#    #+#             */
/*   Updated: 2022/08/01 00:44:53 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_SET_HPP
# define UTILS_SET_HPP

# include <iostream>
# include <sstream>

namespace ft
{

	template <typename T>
	void printSet(T &data)
	{
		std::cout << "size: " << data.size() << std::endl;
		//std::cout << "max_size: " << data.max_size() << std::endl;
		std::cout << "empty: " << data.empty() << std::endl;
		if (data.size() > 0)
		{
			std::cout << "data: ";
			for (typename T::iterator it = data.begin(); it != data.end(); it++)
				std::cout << *it << " | ";
			std::cout << std::endl;
		}
	}

} // namespace ft

#endif // UTILS_SET_HPP