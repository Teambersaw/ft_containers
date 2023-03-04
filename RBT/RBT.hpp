/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:46:36 by jrossett          #+#    #+#             */
/*   Updated: 2023/03/02 12:26:44 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

# include <memory>
# include "../pair.hpp"
# include "map.hpp"
# include <iostream>
# include <cstring>

namespace ft
{
	template <class Value>
	struct Node
	{
		Node	*parent;
		Node	*left;
		Node	*right;
		Value	value;
		bool	color;
	};

	template <class Value>
	class RBT
	{

		public:

			template < class T1, class T2>
			bool comp(const ft::pair<T1, T2> &x, const ft::pair<T1, T2> &y)
			{
				return (x.first < y.first);
			}

			template < class T1, class T2>
			bool comp_key(const ft::pair<T1, T2> &x, const ft::pair<T1, T2> &y)
			{
				return (x.first == y.first);
			}

			RBT() : root(NULL)
			{
					nill = allocator.allocate(1);
			}
			~RBT()
			{
				delete_all(root);
				allocator.deallocate(nill, 1);
			}

			void	delete_all(Node<Value> *del)
			{
				if (del->left != nill)
					delete_all(del->left);
				if (del->right != nill)
					delete_all(del->right);
				alloc.deallocate(del, 1);
			}

			Node<Value>	*new_node(Value value, Node<Value> *parent)
			{
				Node<Value>	*New = alloc.allocate(1);
				New->parent = parent;
				New->left = nill;
				New->right = nill;
				New->value = value;
				New->color = 1;
				return (New);
			}

			void	new_root(Value value)
			{
				root = allocator.allocate(1);
				root->value = value;
				root->color = 0;
				root->parent = nill;
				root->right = nill;
				root->left = nill;
				return ;
			}

			void	insert_node(Value value)
			{
				if (root == NULL)
					return (new_root(value));
				Node<Value>	*tmp = root;
				Node<Value>	*parent;
				while (tmp != nill)
				{
					parent = tmp;
					if (comp(value, tmp->value))
						tmp = tmp->left;
					else if (comp(tmp->value, value))
						tmp = tmp->right;
					else
						return ;
				}
				if (comp(value, parent->value))
				{
					parent->left = new_node(value, parent);
					if (parent->color == 0)
						return ;
					insert_fix(parent->left);
				}
				else if (comp(parent->value, value))
				{
					parent->right = new_node(value, parent);
					if (parent->color == 0)
						return ;
					insert_fix(parent->right);
				}
			}

			void	insert_fix(Node<Value> *n)
			{
				Node<Value> *u;
				while ((n != root) && n->parent->color == 1)
				{
					if (n->parent == n->parent->parent->left)
					{
						u = n->parent->parent->right;
						if (u->color == 1)
						{
							n->parent->color = 0;
							u->color = 0;
							n->parent->parent->color = 1;
							n = n->parent->parent;
						}
						else
						{
							if (n == n->parent->right)
							{
								n = n->parent;
								left_rotate(n);
							}
							n->parent->color = 0;
							n->parent->parent->color = 1;
							right_rotate(n->parent->parent);
						}
					}
					else
					{
						u = n->parent->parent->left;
						if (u->color == 1)
						{
							n->parent->color = 0;
							u->color = 0;
							n->parent->parent->color = 1;
							n = n->parent->parent;
						}
						else
						{
							if (n == n->parent->left)
							{
								n = n->parent;
								right_rotate(n);
							}
							n->parent->color = 0;
							n->parent->parent->color = 1;
							left_rotate(n->parent->parent);
						}
					}
				}
				root->color = 0;
			}

			void	left_rotate(Node<Value> *x)
			{
				Node<Value> *y = x->right;
				x->right = y->left;
				if (y->left != nill)
					y->left->parent = x;
				 y->parent = x->parent;
				if (x->parent == nill)
					root = y;
				else if (x->parent->left == x)
					x->parent->left = y;
				else
					x->parent->right = y;
				y->left = x;
				x->parent = y;
			}

			void	right_rotate(Node<Value> *x)
			{
				Node<Value> *y = x->left;
				x->left = y->right;
				if (y->right != nill)
					y->right->parent = x;
				 y->parent = x->parent;
				if (x->parent == nill)
					root = y;
				else if (x->parent->right == x)
					x->parent->right = y;
				else
					x->parent->left = y;
				y->right = x;
				x->parent = y;
			}

			Node<Value> *searchNode(Value key)
			{
				Node<Value> *node = root;
				while (node != nill)
				{
					if (comp_key(key, node->value))
						return node;
					else if (comp(key, node->value))
						node = node->left;
					else
						node = node->right;
				}
				return node;
			}

			Node<Value> *getNill() const {
				return (nill);
			}
			Node<Value> *getRoot() const {
				return (root);
			}

			Node<Value>	*minimum(Node<Value> *node)
			{
				while (node->left != nill)
					node = node->left;
				return (node);
			}

			Node<Value>	*maximum(Node<Value> *node)
			{
				while (node->right != nill)
					node = node->right;
				return (node);
			}

			void	transplant(Node<Value> *node, Node<Value> *noded)
			{
				if (node->parent == nill)
					root = noded;
				else if (node == node->parent->left)
					node->parent->left = noded;
				else
					node->parent->right = noded;
				noded->parent = node->parent;
			}

			void	delete_node(Value key)
			{
				Node<Value>	*node = searchNode(key);
				if (node == nill)
					return ;
				Node<Value>	*y = node;
				Node<Value>	*x;
				bool	delcolor = y->color;
				if (node->left == nill)
				{
					x = node->right;
					transplant(node, node->right);
				}
				else if (node->right == nill)
				{
					x = node->left;
					transplant(node, node->left);
				}
				else
				{
					y = minimum(node->right);
					delcolor = y->color;
					x = y->right;
					if (y->parent == node)
						x->parent = y;
					else
					{
						transplant(y, y->right);
						y->right = node->right;
						y->right->parent = y;
					}
					transplant(node, y);
					y->left = node->left;
					y->left->parent = y;
					y->color = delcolor;
				}
				allocator.deallocate(node, 1);
				if (delcolor == 0)
					delete_fix(x);
			}

			void	delete_fix(Node<Value>	*node)
			{

			}

		private:
		public:
			std::allocator<Node<Value> > allocator;
			Node<Value> *root;
			Node<Value> *nill;
	};

}

#endif