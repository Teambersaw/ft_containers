/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:24:35 by jrossett          #+#    #+#             */
/*   Updated: 2023/03/01 14:48:01 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "RBT.hpp"
# include "../pair.hpp"
# include <memory>
# include "../iterator.hpp"
# include "../equal.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
	class map
	{
		public:

			typedef				Key												key_type;
			typedef				T												mapped_type;
			typedef				pair<const Key, T>								value_type;
			typedef				Compare											key_compare;
			typedef				Alloc											allocator_type;
			typedef	typename	allocator_type::reference						reference;
			typedef	typename	allocator_type::const_reference					const_reference;
			typedef	typename	allocator_type::pointer							pointer;
			typedef	typename	allocator_type::const_pointer					const_pointer;
			// typedef			RBiter<value_type>								iterator;
			// typedef			CRBiter<value_type>								const_iterator;
			// typedef				ft::reverse_iterator<iterator>					reverse_iterator;
			// typedef				ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			//typedef	typename	ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef				std::size_t										size_type;

			class value_compare: public std::binary_function<value_type, value_type, bool>
			{
				public:

					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;

					result_type operator() (const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					}

				protected:

					key_compare	comp;
					value_compare (Compare c) : comp(c) {}
			};

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _tree(RBT(value_type, _comp, _alloc)), _size(0) {}

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())  : _comp(comp), _alloc(alloc), _tree(RBT(value_type, _comp, _alloc)), _size(0) {
				insert(first, last);
			}

			map (const map& x) : _comp(x.comp), _alloc(x.alloc), _tree(RBT(value_type, _comp, _alloc)), _size(0) {} {
				insert(x.begin(), x.end());
			}

			~map() {}

			map& operator= (const map& x)
			{
				if (this == &x)
					return (*this);
				clear()
				insert(x.begin, x.end);
				return (*this);
			}

			// mapped_type& operator[] (const key_type& k) {
			// 	(*((this->insert(make_pair(k,mapped_type()))).first)).second
			// }

			bool empty() const {
				return (!_size);
			}

			size_type size() const {
				return (_size);
			}

			size_type max_size() const {
				return (_alloc.max_size());
			}

			iterator begin() {
				return (iterator(_tree.minimum(tree.getRoot())));
			}

			const_iterator begin() const {
				return (const_iterator(_tree.minimum(tree.getRoot())));
			}

			iterator end() {
				return (iterator(_tree.getNill()));
			}

			const_iterator end() const {
				return (const_iterator(_tree.getNill()));
			}

			reverse_iterator rbegin() {
				return (reverse_iterator(_tree.getNill()));
			}

			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(_tree.getNill()));
			}

			reverse_iterator rend() {
				return (reverse_iterator(_tree.minimum(tree.getRoot())));
			}

			const_reverse_iterator rend() const {
				return (const_reverse_iterator(_tree.minimum(tree.getRoot())));;
			}

			ft::pair<iterator,bool> insert (const value_type& val) //A TERMINER
			{
				ft::pair<iterator,bool>	pr;

				if (//cond)
				{
					pr.second = true;
					_tree.insert_node(val);
					_size++;
				}
				else
					pr.second = false;
				return (pr);
			}

			iterator insert (iterator position, const value_type& val) {
				(void) position;
				return (insert(val).fisrt);
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {
				while (first != last)
					insert(*(first++));
			}

			void erase (iterator position) { //hohpohpho

			}

			size_type erase (const key_type& k) { //hophohpohp

			}

			void erase (iterator first, iterator last) {
				while (first != last) {
					erase(*(first++));
				}
			}

			allocator_type get_allocator() const { //pas surusrusr
				return (_alloc);
			}

			void swap (map& x) { //hophohp

			}

			void clear() {
				erase(begin(), end());
			}

			key_compare key_comp() const {
				return (_comp);
			}

			value_compare value_comp() const { //????????
				return (_comp);
			}

			iterator find(const key_type &k)
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if (it->first == k)
						return (it);
				}
				return (end());
			}

			const_iterator find(const key_type &k) const
			{
				for (const_iterator it = begin(); it != end(); it++)
				{
					if (it->first == k)
						return (it);
				}
				return (end());
			}

			size_type count (const key_type& k) const
			{
				if (find(k) == end())
					return (0);
				return (1);
			}

			iterator lower_bound(key_type const &k)
			{
				iterator it;

				for (it = begin(); it != end(); it++)
				{
					if (it->first >= k)
						return (it);
				}
				return (it);
			}

			const_iterator lower_bound(key_type const &k) const
			{
				const_iterator it;

				for (it = begin(); it != end(); it++)
				{
					if (it->first >= k)
						return (it);
				}
				return (it);
			}

			iterator upper_bound(key_type const &k)
			{
				iterator it;

				for (it = begin(); it != end(); it++)
				{
					if (it->first > k)
						return (it);
				}
				return (it);
			}

			const_iterator upper_bound(key_type const &k) const
			{
				const_iterator it;

				for (it = begin(); it != end(); it++)
				{
					if (it->first > k)
						return (it);
				}
				return (it);
			}

			pair<const_iterator,const_iterator>	equal_range (const key_type& k) const {
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			pair<iterator,iterator>	equal_range (const key_type& k) {
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

		private:

			allocator_type	_alloc;
			key_compare		_comp;
			RBT				_tree;
			size_type		_size;
	};

	template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key, T, Compare, Alloc>& lhs, ft::map<Key, T, Compare, Alloc>& rhs ) {
		lhs.swap(rhs);
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs )
	{
		if (lhs.size() != rhs.size())
			return (false);

		typename map<Key, T, Compare, Alloc>::const_iterator it1 = lhs.begin();
		typename map<Key, T, Compare, Alloc>::const_iterator it2 = rhs.begin();

		while ((*it1 == *it2) && it1 != lhs.end())
		{
			it1++;
			it2++;
		}
		if (it1 == lhs.end())
			return (true);
		return (false);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs ) {
		return (!(lhs == rhs));
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs ) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs ) {
		return (!(rhs < lhs));
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs ) {
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs ) {
		return (!(lhs < rhs));
	};

}

#endif