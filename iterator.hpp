/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:04:30 by jrossett          #+#    #+#             */
/*   Updated: 2023/02/23 17:02:57 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>
# include <cstddef>

namespace ft
{

	// struct input_iterator_tag {};
	// struct output_iterator_tag {};
	// struct forward_iterator_tag {};
	// struct bidirectional_iterator_tag {};
	// struct random_access_iterator_tag {};

	template <class Iterator> 
	class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	class iterator_traits<T*>
	{
		public:
			typedef ptrdiff_t							difference_type;
			typedef T									value_type;
			typedef T*									pointer;
			typedef T&									reference;
			typedef std::random_access_iterator_tag		iterator_category;
	};

	template <class T>
	class iterator_traits<const T*> 
	{
		public:
			typedef ptrdiff_t							difference_type;
			typedef T									value_type;
			typedef const T*							pointer;
			typedef const T&							reference;
			typedef std::random_access_iterator_tag		iterator_category;
	};

	template <class Iterator>
	class reverse_iterator
	{
		public:

			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;

			reverse_iterator() : it() {}

			explicit reverse_iterator (iterator_type it) : it(it) {}

			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) {
				it = rev_it.base();
			}

			iterator_type base() const {
				return (it);
			}

			reference operator*() const {
				iterator_type tmp = it;
				return (*(--tmp));
			}

			reverse_iterator operator+(difference_type n) const {
				return reverse_iterator(it - n);

			}

			reverse_iterator operator-(difference_type n) const {
				return reverse_iterator(it + n);
			}

			reverse_iterator& operator++() {
				--it;
				return (*this);
			}

			reverse_iterator  operator++(int) {
				reverse_iterator tmp = *this;
				--it;
				return tmp;
			}

			reverse_iterator& operator--() {
				++it;
				return (*this);
			}

			reverse_iterator  operator--(int) {
				reverse_iterator tmp = *this;
				++it;
				return tmp;
			}

			reverse_iterator& operator+= (difference_type n) {
				it -= n;
				return (*this);
			}

			reverse_iterator& operator-= (difference_type n) {
				it += n;
				return (*this);

			}

			reference operator[] (difference_type n) const {
				return (base()[- n - 1]);
			}

			pointer operator->() const {
				return &(operator*());
			}

		private:

			iterator_type it;
	};
}

#endif