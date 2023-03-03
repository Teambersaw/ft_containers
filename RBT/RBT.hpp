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

			RBT() : root(NULL)
			{
					nill = alloc.allocate(1);
			}
			~RBT()
			{
				delete_all(root);
				alloc.deallocate(nill, 1);
			}

			void	delete_all(Node<Value> *root)
			{
				if (root->left != nill)
					delete_all(root->left);
				if (root->right != nill)
					delete_all(root->right);
				alloc.deallocate(root, 1);
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
				root = alloc.allocate(1);
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
					parent->left = new_node(value, parent);
				else if (comp(parent->value, value))
					parent->right = new_node(value, parent);
			}

		private:
		public:
			std::allocator<Node<Value> > alloc;
			Node<Value> *root;
			Node<Value> *nill;
	};

}

#endif