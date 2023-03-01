/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:46:36 by jrossett          #+#    #+#             */
/*   Updated: 2023/03/01 16:25:29 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

# include <memory>
# include "../pair.hpp"
# include "map.hpp"

namespace ft
{
	template <class Value>
	struct Node {
		Node	*parent;
		Node	*left;
		Node	*right;
		Value	value;
		bool	color;
	};

	template <class Value>
	class RBT {

		public:

			RBT() : root(NULL) {}
			~RBT() {}

			Node<Value>	*new_node(Value value, Node<Value> *parent)
			{
				Node<Value>	*New = alloc.allocate(1);
				New->parent = parent;
				New->left = nill;
				New->right = nill;
				New->value = value;
				New->color = 0;
				return (New);
			}

			void	insert_node(Value value)
			{
				if (root == NULL) {
					root = alloc.allocate(1);
					root->value = value;
					root->color = 0;
					root->parent = nill;
					root->right = nill;
					root->left = nill;
					return ;
				}
				Node<Value> *tmp = root;
				while (tmp->left != nill && tmp->right != nill)
				{
					if (value < tmp->value)
						tmp = tmp->left;
					else
						tmp = tmp->right;
				}
				if (value < tmp->value)
					tmp->left = new_node(value, tmp->left);
				else
					tmp->right = new_node(value, tmp->right);
			}

		private:

			std::allocator<Node<Value> > alloc;
			Node<Value> *root;
			Node<Value> *nill;
	};

}

#endif