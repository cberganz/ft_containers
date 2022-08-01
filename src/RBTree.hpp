/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:02:21 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/27 01:26:59by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <stdint.h>
# include <iostream>
# include <stdlib.h>
# include "utility/is_integral.hpp"
# include "utility/pair.hpp"
# include "utility/node_base.hpp"
# include "utility/RBTree_iterator.hpp"
# include "utility/reverse_iterator.hpp"
# include "utility/equal.hpp"
# include "utility/lexicographical_compare.hpp"

namespace ft {

template <typename Key, typename KeyOfValue, typename Val = Key, class Compare = std::less<Key>, class Allocator = std::allocator<Val> >
class RBTree {

private:
	typedef typename Allocator::template rebind<ft::Node<Val> >::other	NodeAlloc;
	typedef RBTree<Key, Val, Compare, Allocator>						self;

public:
	typedef Key												key_type;
	typedef Compare											key_compare;
	typedef Val												value_type;
	typedef value_type *									pointer;
	typedef const value_type *								const_pointer;
	typedef value_type &									reference;
	typedef const value_type &								const_reference;
	typedef size_t											size_type;
	typedef std::ptrdiff_t									difference_type;
	typedef Allocator										allocator_type;
	typedef ft::RBTree_iterator<Val>						iterator;
	typedef ft::RBTree_const_iterator<Val>					const_iterator;
	typedef ft::reverse_iterator<iterator>					reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

protected:
	typedef ft::Node<Val> *		NodePtr;
	
	NodePtr		header;
	size_t		len;
	NodeAlloc	allocator;
	Compare		compare;

	void
	leftRotate(NodePtr x)
	{
		NodePtr y = x->right;
		x->right = y->left;
		if (y->left != 0)
			y->left->parent = x;
		y->parent = x->parent;
		if (x->parent == 0)
			header->parent = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x;
		x->parent = y;
	}

	void
	rightRotate(NodePtr x)
	{
		NodePtr y = x->left;
		x->left = y->right;
		if (y->right != 0)
			y->right->parent = x;
		y->parent = x->parent;
		if (x->parent == 0)
			header->parent = y;
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
		y->right = x;
		x->parent = y;
	}

	void
	rbTransplant(NodePtr x, NodePtr y)
	{
		if (x->parent == 0)
			header->parent = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		if (y != 0)
			y->parent = x->parent;
	}

	void
	setHeader()
	{
		if (header->parent)
		{
			header->parent->parent = header;
			header->right = getMin();
			header->left = getMax();
		}
	}

	void
	insertFix(NodePtr k)
	{
		NodePtr u;
		while (k->parent->color == RED)
		{
			if (k->parent == k->parent->parent->right)
			{
				u = k->parent->parent->left;
				if (u != 0 and u->color == RED)
				{
					u->color = BLACK;
					k->parent->color = BLACK;
					k->parent->parent->color = RED;
					k = k->parent->parent;
				}
				else
				{
					if (k == k->parent->left)
					{
						k = k->parent;
						rightRotate(k);
					}
					k->parent->color = BLACK;
					k->parent->parent->color = RED;
					leftRotate(k->parent->parent);
				}
			}
			else
			{
				u = k->parent->parent->right;
				if (u != 0 and u->color == RED)
				{
					u->color = BLACK;
					k->parent->color = BLACK;
					k->parent->parent->color = RED;
					k = k->parent->parent;
				}
				else
				{
					if (k == k->parent->right)
					{
						k = k->parent;
						leftRotate(k);
					}
					k->parent->color = BLACK;
					k->parent->parent->color = RED;
					rightRotate(k->parent->parent);
				}
			}
			if (k == header->parent)
				break;
		}
		header->parent->color = BLACK;
	}

	void
	deleteFix(NodePtr x)
	{
		NodePtr s;
		while (x != 0 and x != header and x->parent != 0 and x->color == BLACK)
		{
			if (x == x->parent->left)
			{
				s = x->parent->right;
				if (s->color == RED)
				{
					s->color = BLACK;
					x->parent->color = RED;
					leftRotate(x->parent);
					s = x->parent->right;
				}
				if (s->left->color == BLACK and s->right->color == BLACK)
				{
					s->color = RED;
					x = x->parent;
				}
				else
				{
					if (s->right->color == BLACK)
					{
						s->left->color = BLACK;
						s->color = RED;
						rightRotate(s);
						s = x->parent->right;
					}
					s->color = x->parent->color;
					x->parent->color = BLACK;
					s->right->color = BLACK;
					leftRotate(x->parent);
					x = header->parent;
				}
			}
			else
			{
				s = x->parent->left;
				if (s->color == RED)
				{
					s->color = BLACK;
					x->parent->color = RED;
					rightRotate(x->parent);
					s = x->parent->left;
				}
				if (s->left->color == BLACK and s->right->color == BLACK)
				{
					s->color = RED;
					x = x->parent;
				}
				else
				{
					if (s->left->color == BLACK)
					{
						s->right->color = BLACK;
						s->color = RED;
						leftRotate(s);
						s = x->parent->left;
					}
					s->color = x->parent->color;
					x->parent->color = BLACK;
					s->left->color = BLACK;
					rightRotate(x->parent);
					x = header->parent;
				}
			}
		}
		if (x)
			x->color = BLACK;
		if (len == 0)
			clear();
	}

	NodePtr
	find_impl(const NodePtr &node, const Key &toFind)
	const
	{
		if (node == 0 || node == header)
			return header;
		if (not compare(node->data, toFind) and not compare(toFind, node->data))
			return node;
		return find_impl((compare(toFind, node->data) ? node->left : node->right), toFind);
	}

	void
	clear_impl(NodePtr node)
	{
		if (node)
		{
			clear_impl(node->right);
			clear_impl(node->left);
			allocator.destroy(node);
			allocator.deallocate(node, 1);
		}
	}

	NodePtr
	getMin()
	const
	{ return getMinFrom(header->parent); }

	NodePtr
	getMax()
	const
	{ return getMaxFrom(header->parent); }

	NodePtr
	getMinFrom(const NodePtr &node)
	const
	{ return (node != 0 and node != header and node->left != 0 and node->left != header ? getMinFrom(node->left) : node); }

	NodePtr
	getMaxFrom(const NodePtr &node)
	const
	{ return (node != 0 and node != header and node->right != 0 and node->right != header ? getMaxFrom(node->right) : node); }

	void
	printTreeHelper(NodePtr root, std::string indent, bool last)
	{
		if (root != 0 and root != header)
		{
			std::cout << indent;
			if (last)
			{
				std::cout << "R----";
				indent += "   ";
			}
			else
			{
				std::cout << "L----";
				indent += "|  ";
			}
			std::string sColor = root->color ? "RED" : "BLACK";
			std::cout << root->data.second << "(" << sColor << ")" << std::endl;
			printTreeHelper(root->left, indent, false);
			printTreeHelper(root->right, indent, true);
		}
	}

public:
	RBTree(const Compare &_compare, const NodeAlloc &_allocator)
		: allocator(_allocator),
		  compare(_compare)
	{
		len = 0;
		header = allocator.allocate(1);
		allocator.construct(header, ft::Node<Val>());
		header->parent = 0;
		header->right = header;
		header->left = header;
	}

	template <class InputIterator>
	RBTree(InputIterator first, InputIterator last,
		   const Compare& _compare, const Allocator& _allocator)
		: allocator(_allocator),
		  compare(_compare)
	{
		len = 0;
		header = allocator.allocate(1);
		allocator.construct(header, ft::Node<Val>());
		header->parent = 0;
		header->right = header;
		header->left = header;
		insert(first, last);
	}

	~RBTree()
	{
		clear();
		allocator.destroy(header);
		allocator.deallocate(header, 1);
	}

	self &
	operator=(const self &rhs)
	{
		if (this == &rhs)
			return *this;
		clear();
		insert(rhs.begin(), rhs.end());
		return *this;
	}

	void
	printTree()
	{ printTreeHelper(header->parent, "", true); }

	/******************************
				iterators
	******************************/

	iterator
	begin()
	{ return iterator(header->right); }

	const_iterator
	begin()
	const
	{ return const_iterator(header->right); }

	iterator
	end()
	{ return iterator(header); }

	const_iterator
	end()
	const
	{ return const_iterator(header); }

	reverse_iterator
	rbegin()
	{ return reverse_iterator(end()); }

	const_reverse_iterator
	rbegin()
	const
	{ return const_reverse_iterator(end()); }

	reverse_iterator
	rend()
	{ return reverse_iterator(begin()); }

	const_reverse_iterator
	rend()
	const
	{ return const_reverse_iterator(begin()); }

	/******************************
				capacity
	******************************/

	bool
	empty()
	const
	{ return len == 0; }

	size_t
	size()
	const
	{ return len; }

	size_t
	max_size()
	const
	{ return allocator.max_size(); }

	/******************************
	 			Modifiers
	******************************/

	ft::pair<iterator, bool>
	insert(const value_type &val)
	{
		NodePtr node = find_impl(header->parent, KeyOfValue()(val));
		if (node != header)
			return ft::make_pair(iterator(node), false);
		node = allocator.allocate(1);
		allocator.construct(node, ft::Node<Val>(val));
		if (header->parent)
			header->parent->parent = 0;
		NodePtr x = header->parent, y = 0;
		while (x != 0 and x != header)
		{
			y = x;
			if (compare(node->data, x->data))
				x = x->left;
			else
				x = x->right;
		}
		node->parent = y;
		if (y == 0)
			header->parent = node;
		else
			compare(node->data, y->data) ? y->left = node : y->right = node;
		if (node->parent == 0)
			node->color = BLACK;
		else if (node->parent->parent != 0)
			insertFix(node);
		setHeader();
		len++;
		return ft::make_pair(iterator(node), true);
	}

	iterator
	insert(iterator position, const value_type& val)
	{
		static_cast<void>(position);
		return insert(val).first;
	}

	iterator
	insert(const_iterator position, const value_type& val)// A LAISSER POUR SET ?
	{
		static_cast<void>(position);
		return insert(val).first;
	}

	template <class InputIterator>
	void
	insert(InputIterator first, InputIterator last)
	{
		while (first != last)
		{
			static_cast<void>(insert(*first));
			first++;
		}
	}

	size_type
	erase(const key_type &key)
	{
		NodePtr z = find_impl(header->parent, key);
		if (z == header)
			return 0; // Key not found
		NodePtr x, y;
		if(header->parent)
			header->parent->parent = 0;
		y = z;
		RBTree_colors yColor = y->color;
		if (z->left == 0)
		{
			x = z->right;
			rbTransplant(z, z->right);
		}
		else if (z->right == 0)
		{
			x = z->left;
			rbTransplant(z, z->left);
		}
		else
		{
			y = getMinFrom(z->right);
			yColor = y->color;
			x = y->right;
			if (x and y->parent == z)
				x->parent = y;
			else
			{
				rbTransplant(y, y->right);
				y->right = z->right;
				if (y->right)
					y->right->parent = y;
			}
			rbTransplant(z, y);
			y->left = z->left;
			if (y->left)
				y->left->parent = y;
			y->color = z->color;
		}
		allocator.destroy(z);
		allocator.deallocate(z, 1);
		len--;
		if (yColor == BLACK)
			deleteFix(x);
		setHeader();
		return 1;
	}

	void
	erase(iterator position)
	{ erase(KeyOfValue()(*position)); }

	void
	erase(const_iterator position)		// A LAISSER POUR SET ?
	{ erase(KeyOfValue()(*position)); }

	void
	erase(iterator first, iterator last)
	{
		while (first != last)
			erase(first++);
	}

	void
	erase(const_iterator first, const_iterator last) // A LAISSER POUR SET ?
	{
		while (first != last)
			erase(first++);
	}

	void swap(RBTree &other)
	{
		NodePtr header = this->header;
		size_t len = this->len;
		NodeAlloc nodeAlloc = this->allocator;
		this->header = other.header;
		this->len = other.len;
		this->allocator = other.allocator;
		other.header = header;
		other.len = len;
		other.allocator = nodeAlloc;
	}

	void
	clear()
	{
		clear_impl(header->parent);
		header->parent = 0;
		header->right = header;
		header->left = header;
		len = 0;
	}

	/******************************
				Observers
	******************************/

	key_compare
	key_comp()
	const
	{ return compare; }

	allocator_type
	get_allocator()
	const
	{ return allocator; }

	/******************************
				Operations
	******************************/

	iterator
	find(const key_type &x)
	{ return iterator(find_impl(header->parent, x)); }

	const_iterator
	find(const key_type &x)
	const
	{ return const_iterator(find_impl(header->parent, x)); }

	size_type
	count(const key_type& k)
	const
	{
		NodePtr tmp = find_impl(header->parent, k);
		return (tmp == 0 or tmp == header ? 0 : 1);
	}

	iterator
	lower_bound(const key_type& k)
	{
		NodePtr node = header->parent, ret = header;
		while (node != 0 and node != header)
		{
			if (not compare(node->data, k))
			{
				ret = node;
				node = node->left;
			}
			else
				node = node->right;
		}
		return iterator(ret);
	}

	const_iterator
	lower_bound(const key_type& k)
	const
	{
		NodePtr node = header->parent, ret = header;
		while (node != 0 and node != header)
		{
			if (not compare(node->data, k))
			{
				ret = node;
				node = node->left;
			}
			else
				node = node->right;
		}
		return const_iterator(ret);
	}

	iterator
	upper_bound(const key_type& k)
	{
		NodePtr node = header->parent, ret = header;
		while (node != 0 and node != header)
		{
			if (compare(k, node->data))
			{
				ret = node;
				node = node->left;
			}
			else
				node = node->right;
		}
		return iterator(ret);
	}

	const_iterator
	upper_bound(const key_type& k)
	const
	{
		NodePtr node = header->parent, ret = header;
		while (node != 0 and node != header)
		{
			if (compare(k, node->data))
			{
				ret = node;
				node = node->left;
			}
			else
				node = node->right;
		}
		return const_iterator(ret);
	}

	ft::pair<iterator, iterator>
	equal_range(const key_type& k)
	{ return ft::make_pair(lower_bound(k), upper_bound(k)); }

	ft::pair<const_iterator, const_iterator>
	equal_range(const key_type& k)
	const
	{ return ft::make_pair(lower_bound(k), upper_bound(k)); }

}; // class RBTree

/******************************
	  operators overload
******************************/

template <typename _Key, typename _Val, class _Compare, class _Allocator>
inline bool
operator==(const ft::RBTree<_Key, _Val, _Compare, _Allocator> &lhs,
		   const ft::RBTree<_Key, _Val, _Compare, _Allocator> &rhs)
{
	return lhs.size() == rhs.size()
		   and ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <typename _Key, typename _Val, class _Compare, class _Allocator>
inline bool
operator<(const ft::RBTree<_Key, _Val, _Compare, _Allocator> &lhs,
		  const ft::RBTree<_Key, _Val, _Compare, _Allocator> &rhs)
{ return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); } // + comp ?

template <typename _Key, typename _Val, class _Compare, class _Allocator>
inline bool
operator!=(const ft::RBTree<_Key, _Val, _Compare, _Allocator> &lhs,
		   const ft::RBTree<_Key, _Val, _Compare, _Allocator> &rhs)
{ return not (lhs == rhs); }

template <typename _Key, typename _Val, class _Compare, class _Allocator>
inline bool
operator>(const ft::RBTree<_Key, _Val, _Compare, _Allocator> &lhs,
		  const ft::RBTree<_Key, _Val, _Compare, _Allocator> &rhs)
{ return rhs < lhs; }

template <typename _Key, typename _Val, class _Compare, class _Allocator>
inline bool
operator>=(const ft::RBTree<_Key, _Val, _Compare, _Allocator> &lhs,
		   const ft::RBTree<_Key, _Val, _Compare, _Allocator> &rhs)
{ return not (lhs < rhs); }

template <typename _Key, typename _Val, class _Compare, class _Allocator>
inline bool
operator<=(const ft::RBTree<_Key, _Val, _Compare, _Allocator> &lhs,
		   const ft::RBTree<_Key, _Val, _Compare, _Allocator> &rhs)
{ return not (rhs < lhs); }

/******************************
	specialized algorithm
******************************/

template <typename _Key, typename _Val, class _Compare, class _Allocator>
void
swap(ft::RBTree<_Key, _Val, _Compare, _Allocator> &x, ft::RBTree<_Key, _Val, _Compare, _Allocator> &y)
{ x.swap(y); }

/******************************
	  iterator specifics
******************************/

template <typename T>
T
RBT_increment(T &x)
{
	if (x->right != 0) 
	{
		x = x->right;
		while (x->left != 0)
			x = x->left;
	}
	else
	{
		T y = x->parent;
		while (x == y->right)
		{
			x = y;
			y = y->parent;
		}
		if (x->right != y)
			x = y;
	}
	return x;
}

template <typename T>
T
RBT_decrement(T &x)
{
	T y;
	if (x->left != 0) 
	{
		y = x->left;
		while (y->right != 0)
			y = y->right;
	}
	else
	{
		y = x->parent;
		while (x == y->left)
		{
			x = y;
			y = y->parent;
		}
	}
	return y;
}

} // namespace ft

#endif //RBTREE_HPP