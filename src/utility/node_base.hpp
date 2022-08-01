/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_base.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:07:53 by cberganz          #+#    #+#             */
/*   Updated: 2022/07/31 03:46:26 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_BASE_HPP
# define NODE_BASE_HPP

namespace ft {

enum RBTree_colors { RED = false, BLACK = true };

template <typename T>
struct Node {

	T				data;
	RBTree_colors	color;
	Node			*parent;
	Node			*right;
	Node			*left;
	
	Node()
		: color(RED), parent(0), right(0), left(0)
	{}
	
	Node(const T &data)
		: data(data), color(RED), parent(0), right(0), left(0)
	{}

};	// struct Node

}	// namespace ft

#endif	// NODE_BASE_HPP