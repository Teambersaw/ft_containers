/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:26:03 by jrossett          #+#    #+#             */
/*   Updated: 2023/03/17 15:25:55 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include "RBT.hpp"
# include <memory>
# include "iterator.hpp"
# include "equal.hpp"
# include "pair.hpp"
# include "tree_iter.hpp"
# include <algorithm>

namespace ft
{
	template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set
	{
		public:

			typedef				T												key_type;
			typedef				T												value_type;
			typedef				Compare											key_compare;
			typedef				Compare											value_compare;
			typedef				Alloc											allocator_type;
			typedef	typename	allocator_type::reference						reference;
			typedef	typename	allocator_type::const_reference					const_reference;
			typedef	typename	allocator_type::pointer							pointer;
			typedef	typename	allocator_type::const_pointer					const_pointer;
			typedef				CRBiter<value_type>								iterator;
			typedef				CRBiter<value_type>								const_iterator;
			typedef				ft::reverse_iterator<iterator>					reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef	typename	ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef				std::size_t										size_type;
			typedef Node<value_type>*											node_t;

			explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _tree(RBT<key_type, allocator_type, Compare>(_comp)), _size(0) {}

			template <class InputIterator>
			set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())  : _comp(comp), _alloc(alloc), _tree(RBT<key_type, allocator_type, Compare>(_comp)), _size(0) {
				insert(first, last);
			}

			set (const set& x) : _comp(x._comp), _alloc(x._alloc), _tree(RBT<key_type , allocator_type, Compare>(_comp)), _size(0) {
				insert(x.begin(), x.end());
			}

			virtual ~set() {}

			set& operator= (const set& x)
			{
				if (this == &x)
					return (*this);
				clear();
				insert(x.begin(), x.end());
				return (*this);
			}

			bool empty() const {
				return (!_size);
			}

			size_type size() const {
				return (_size);
			}

			size_type max_size() const {
				return ((_tree.get_allocator()).max_size());
			}

			iterator begin() {
				return (iterator(_tree.min()));
			}

			const_iterator begin() const {
				return (const_iterator(_tree.min()));
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
				return (reverse_iterator(_tree.min()));
			}

			const_reverse_iterator rend() const {
				return (const_reverse_iterator(_tree.min()));
			}

			ft::pair<iterator,bool> insert (const value_type& val)
			{
				ft::pair<Node<value_type> *, bool>	pr = _tree.insert_node(val);
				if (!pr.second)
					return (pr);
				_size++;
				return (pr);
			}

			iterator insert (iterator position, const key_type& val) {
				(void) position;
				return (insert(val).first);
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {
				while (first != last)
					insert(*(first)++);
			}

			void erase (iterator position) {
				_tree.delete_node(position.base()->value);
				_size--;
			}

			size_type erase (const key_type& k) {
				iterator it = find(k);
				if (it == end())
					return (0);
				_tree.delete_node(it.base()->value);
				_size--;
				return (1);
			}

			void erase (iterator first, iterator last) {
				while (first != last) {
					erase(first++);
				}
			}

			allocator_type get_allocator() const {
				return (_tree.get_allocator());
			}

			void swap (set& x)
			{
				std::swap(this->_size, x._size);
				this->_tree.rbt_swap(x._tree);
			}

			void clear() {
				erase(begin(), end());
			}

			key_compare key_comp() const {
				return (_comp);
			}

			key_compare value_comp() const {
				return (_comp);
			}

			iterator find(const key_type &k)
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if (*it == k)
						return (it);
				}
				return (end());
			}

			const_iterator find(const key_type &k) const
			{
				for (const_iterator it = begin(); it != end(); it++)
				{
					if (*it == k)
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
					if (*it >= k)
						return (it);
				}
				return (it);
			}

			const_iterator lower_bound(key_type const &k) const
			{
				const_iterator it;

				for (it = begin(); it != end(); it++)
				{
					if (*it >= k)
						return (it);
				}
				return (it);
			}

			iterator upper_bound(key_type const &k)
			{
				iterator it;

				for (it = begin(); it != end(); it++)
				{
					if (*it > k)
						return (it);
				}
				return (it);
			}

			const_iterator upper_bound(key_type const &k) const
			{
				const_iterator it;

				for (it = begin(); it != end(); it++)
				{
					if (*it > k)
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

			key_compare		_comp;
			allocator_type	_alloc;
			RBT<key_type, allocator_type, Compare>		_tree;
			size_type		_size;
	};

	template< class T, class Compare, class Alloc >
	void swap( ft::set<T, Compare, Alloc>& lhs, ft::set<T, Compare, Alloc>& rhs ) {
		lhs.swap(rhs);
	};

	template<class T, class Compare, class Alloc >
	bool operator==( const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs )
	{
		if (lhs.size() != rhs.size())
			return (false);

		typename set<T, Compare, Alloc>::const_iterator it1 = lhs.begin();
		typename set<T, Compare, Alloc>::const_iterator it2 = rhs.begin();

		while ((*it1 == *it2) && it1 != lhs.end())
		{
			it1++;
			it2++;
		}
		if (it1 == lhs.end())
			return (true);
		return (false);
	}

	template< class T, class Compare, class Alloc >
	bool operator!=( const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs ) {
		return (!(lhs == rhs));
	};

	template< class T, class Compare, class Alloc >
	bool operator<( const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs ) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};

	template< class T, class Compare, class Alloc >
	bool operator<=( const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs ) {
		return (!(rhs < lhs));
	};

	template< class T, class Compare, class Alloc >
	bool operator>( const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs ) {
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	};

	template< class T, class Compare, class Alloc >
	bool operator>=( const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs ) {
		return (!(lhs < rhs));
	};

}

#endif