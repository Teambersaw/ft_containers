/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:46:36 by jrossett          #+#    #+#             */
/*   Updated: 2023/02/28 16:35:20 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

template <class Key>
struct Node {
	Node	*parent;
	Node	*right;
	Node	*left;
	Key		key;
	bool	color;
};

template <class Key>
class RBT {

	public:

		RBT() : root(NULL) {}
		~RBT() {}

	private:

		Node<Key> *root;
};

#endif