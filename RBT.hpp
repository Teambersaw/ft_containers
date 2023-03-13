/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:46:36 by jrossett          #+#    #+#             */
/*   Updated: 2023/03/13 17:01:16 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

# include <memory>
//# include "map.hpp"
# include <iostream>
# include <cstring>

namespace ft
{
	template <class Value>
	struct Node
	{
			Value	value;
			Node	*parent;
			Node	*left;
			Node	*right;
			bool	color;

			Node() : parent(NULL), left(NULL), right(NULL), color(0) {}
			Node(Value &val) : value(val), parent(NULL), left(NULL), right(NULL), color(0) {}
			~Node() {}
	};

	template <class Value, class allocator_type, class comp>
	class RBT
	{

		public:

			typedef typename allocator_type::template rebind<Node<Value> >::other Alloc;

			RBT(comp compare) : _comp(compare)
			{
					nill = allocator.allocate(1);
					root = nill;
					nill->parent = nill;
					nill->left = NULL;
					nill->right = NULL;
					nill->color = 0;
			}
			~RBT()
			{
				if (root != NULL && root != nill)
					delete_all(root);
				allocator.deallocate(nill, 1);
			}

			void	delete_all(Node<Value> *del)
			{
				if (del->left != nill)
					delete_all(del->left);
				if (del->right != nill)
					delete_all(del->right);
				allocator.destroy(del);
				allocator.deallocate(del, 1);
			}

			Node<Value>	*new_node(Value value, Node<Value> *parent)
			{
				Node<Value>	*New = allocator.allocate(1);
				allocator.construct(New, value);
				New->parent = parent;
				New->left = nill;
				New->right = nill;
				New->color = 1;
				if (nill->parent == nill)
					nill->parent = New;
				else if (_comp(nill->parent->value, New->value))
					nill->parent = New;
				return (New);
			}

			Node<Value>	*insert_node(Value value)
			{
				if (root == nill) {
					root = new_node(value, nill);
					root->color = 0;
					return root;
				}
				Node<Value>	*tmp = root;
				Node<Value>	*parent;
				while (tmp != nill) //inutile ?
				{
					parent = tmp;
					if (_comp(value, tmp->value))
						tmp = tmp->left;
					else if (_comp(tmp->value, value))
						tmp = tmp->right;
				}
				if (_comp(value, parent->value))
				{
					parent->left = new_node(value, parent);
					if (parent->color == 1)
						insert_fix(parent->left);
					return parent->left;
				}
				else if (_comp(parent->value, value))
				{
					parent->right = new_node(value, parent);
					if (parent->color == 1)
						insert_fix(parent->right);
					return parent->right;
				}
				return (NULL);
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
					if (!_comp(key, node->value) && !_comp(node->value, key))
						return node;
					else if (_comp(key, node->value))
						node = node->left;
					else
						node = node->right;
				}
				return node;
			}

			Node<Value> *getNill() const {
				return (nill);
			}

			Node<Value> const *getRoot() const {
				return (root);
			}

			Node<Value> *min() const {
				return (minimum(root));
			}

			Node<Value> *max() const {
				return (maximum(root));
			}
			Node<Value>	*minimum(Node<Value> *node) const
			{
				Node<Value> *tmp = node;

				while (tmp != nill && tmp->left != nill)
					tmp = tmp->left;
				return (tmp);
			}

			Node<Value>	*maximum(Node<Value> *node) const
			{
				Node<Value> *tmp = node;

				while (tmp != nill && tmp->right != nill)
					tmp = tmp->right;
				return (tmp);
			}

			Alloc const &get_allocator() const {
				return (this->allocator);
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
				Node<Value>	*w;
				while (node != root && node->color == 0)
				{
					if (node == node->parent->left)
					{
						w = node->parent->right;
						if (node->parent->right->color == 1)
						{
							node->parent->right->color = 0;
							node->parent->color = 1;
							left_rotate(node->parent);
							w = node->parent->right;
						}
						if (w->left->color == 0 && w->right->color == 0)
						{
							w->color = 1;
							node = node->parent;
						}
						else
						{
							if (w->right->color == 0)
							{
								w->left->color = 0;
								w->color = 1;
								right_rotate(w);
								w = node->parent->right;
							}
							w->color = node->parent->color;
							node->parent->color = 0;
							w->right->color = 0;
							left_rotate(node->parent);
							node = root;
						}
					}
					else
					{
						w = node->parent->left;
						if (node->parent->left->color == 1)
						{
							node->parent->left->color = 0;
							node->parent->color = 1;
							right_rotate(node->parent);
							w = node->parent->left;
						}
						if (w->right->color == 0 && w->left->color == 0)
						{
							w->color = 1;
							node = node->parent;
						}
						else 
						{
							if (w->left->color == 0)
							{
								w->right->color = 0;
								w->color = 1;
								left_rotate(w);
								w = node->parent->left;
							}
							w->color = node->parent->color;
							node->parent->color = 0;
							w->left->color = 0;
							right_rotate(node->parent);
							node = root;
						}
					}
				}
				node->color = 0;
			}

			void rbt_swap(RBT& x)
			{
				std::swap(x.nill, nill);
				std::swap(x.root, root);
			}

		private:

			Alloc			allocator;
			Node<Value>		*root;
			comp			_comp;
			Node<Value>		*nill;
	};

}

#endif