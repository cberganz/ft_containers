/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:19:34 by cberganz          #+#    #+#             */
/*   Updated: 2022/08/01 02:48:01 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_ITERATOR
# define RBTREE_ITERATOR

# include "iterator_base.hpp"
# include "../RBTree.hpp"
# include "node_base.hpp"

namespace ft {

template <typename T>
struct RBTree_iterator : ft::iterator<std::bidirectional_iterator_tag, T> {

private:
	typedef typename ft::iterator<std::bidirectional_iterator_tag, T>	iterator;
	typedef ft::Node<T>*												link_type;

public:
	typedef T											value_type;
	typedef typename std::bidirectional_iterator_tag	iterator_category;
	typedef typename iterator::difference_type			difference_type;
	typedef typename iterator::pointer					pointer;
	typedef typename iterator::reference				reference;

	link_type	node;

	RBTree_iterator()
		: node()
	{}

	explicit
	RBTree_iterator(link_type node)
		: node(node)
	{}

	RBTree_iterator(const RBTree_iterator &src)
		: node(src.node)
	{}

	~RBTree_iterator()
	{}

	RBTree_iterator &
	operator++()
	{
		node = RBT_increment(node);
		return *this;
	}
	
	RBTree_iterator
	operator++(int)
	{
		RBTree_iterator tmp = *this;
		node = RBT_increment(node);
		return tmp;
	}
	
	RBTree_iterator &
	operator--()
	{
		node = RBT_decrement(node);
		return *this;
	}
	
	RBTree_iterator
	operator--(int)
	{
		RBTree_iterator tmp = *this;
		node = RBT_decrement(node);
		return tmp;
	}

	RBTree_iterator &
	operator=(const RBTree_iterator &rhs)
	{
		if (*this == rhs)
			return (*this);
		this->node = rhs.node;
		return *this;
	}

	bool
	operator==(const RBTree_iterator &rhs)
	const
	{ return this->node == rhs.node; }

	bool
	operator!=(const RBTree_iterator &rhs)
	const
	{ return this->node != rhs.node; }

	reference
	operator*()
	const
	{ return node->data; }

	pointer
	operator->()
	const
	{ return &node->data; }

};	// struct RBTree_iterator

template<typename T>
struct RBTree_const_iterator : ft::iterator<std::bidirectional_iterator_tag, T> {

private:
	typedef typename ft::iterator<std::bidirectional_iterator_tag, T>	iterator;
	typedef ft::Node<T>*												link_type;

public:
	typedef typename std::bidirectional_iterator_tag	iterator_category;
	typedef typename iterator::difference_type			difference_type;
	typedef T											value_type;
	typedef const T *									pointer;
	typedef const T &									reference;

	link_type	node;

	RBTree_const_iterator()
		: node()
	{}
	
	explicit
	RBTree_const_iterator(link_type node)
		: node(node)
	{}
	
	RBTree_const_iterator(const RBTree_const_iterator &src)
		: node(src.node)
	{}

	RBTree_const_iterator(const RBTree_iterator<T> &src)
		: node(src.node)
	{}

	reference
	operator*()
	const
	{ return node->data; }

	pointer
	operator->()
	const
	{ return &node->data; }

	RBTree_const_iterator &
	operator++()
	{
		node = RBT_increment(node);
		return *this;
	}
	
	RBTree_const_iterator
	operator++(int)
	{
		RBTree_const_iterator tmp = *this;
		node = RBT_increment(node);
		return tmp;
	}

	RBTree_const_iterator &
	operator--()
	{
		node = RBT_decrement(node);
		return *this;
	}
	
	RBTree_const_iterator
	operator--(int)
	{
		RBTree_const_iterator tmp = *this;
		node = RBT_decrement(node);
		return tmp;
	}

	bool
	operator==(const RBTree_const_iterator &rhs)
	const
	{ return this->node == rhs.node; }

	bool
	operator!=(const RBTree_const_iterator &rhs)
	const
	{ return this->node != rhs.node; }

};	// struct RBTree_const_iterator

template <typename T>
inline bool
operator==(const RBTree_iterator<T> &lhs,
   		   const RBTree_const_iterator<T> &rhs)
{ return lhs.node == rhs.node; }
	
template <typename T>
inline bool
operator!=(const RBTree_iterator<T> &lhs,
		   const RBTree_const_iterator<T> &rhs)
{ return lhs.node != rhs.node; }

template <typename T>
inline bool
operator==(const RBTree_const_iterator<T> &lhs,
   		   const RBTree_iterator<T> &rhs)
{ return lhs.node == rhs.node; }
	
template <typename T>
inline bool
operator!=(const RBTree_const_iterator<T> &lhs,
		   const RBTree_iterator<T> &rhs)
{ return lhs.node != rhs.node; }

}	// namespace ft

#endif	// RBTREE_ITERATOR_HPP