/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 02:07:41 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/16 23:55:19 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <sstream>
# include "../vector.hpp"
# include "is_integral.hpp"
# include "random_access_iterator.hpp"

namespace ft
{

	template <typename T>
	std::string
	toStr(const T &n)
	{
		std::ostringstream ss;
		ss << n;
		return (ss.str());
	}

	template <typename T>
	void printValues(const T &data)
	{
		std::cout << "size: " << data.size() << std::endl;
		std::cout << "capacity: " << data.capacity() << std::endl;
		std::cout << "max_size: " << data.max_size() << std::endl;
		std::cout << "empty: " << data.empty() << std::endl;
		if (data.size() > 0)
		{
			std::cout << "front: " << data.front() << std::endl;
			std::cout << "back: " << data.back() << std::endl;
			std::cout << "data: ";
			for (size_t i = 0; i < data.size(); i++)
			{
				std::cout << data[i];
				if (i + 1 != data.size())
					std::cout << " | ";
				else
					std::cout << std::endl;
			}
		}
	}

	template <typename T>
	void printStack(T data)
	{
		std::cout << "size: " << data.size() << std::endl;
		std::cout << "empty: " << data.empty() << std::endl;
		if (data.size() > 0)
		{
			std::cout << "top: " << data.top() << std::endl;
			std::cout << "data: ";
			for (size_t i = 0; i < data.size(); i++)
			{
				std::cout << data.top();
				data.pop();
				if (i + 1 != data.size())
					std::cout << " | ";
				else
					std::cout << std::endl;
			}
		}
	}

	template <class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
	difference(InputIterator first, InputIterator last)
	{
		typename ft::iterator_traits<InputIterator>::difference_type rtn = 0;
		while (first != last)
		{
			first++;
			rtn++;
		}
		return (rtn);
	}

} // namespace ft

#endif // UTILS_HPP