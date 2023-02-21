/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:47:02 by jrossett          #+#    #+#             */
/*   Updated: 2023/02/21 16:28:27 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "iterator.hpp"
# include <iterator>
# include "is_integral.hpp"
# include <stdexcept>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:

			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef std::size_t												size_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef pointer													iterator;
			typedef const_pointer											const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type		difference_type;

			explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _size(0), _vector(NULL) {}

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(n), _capacity(n) {
				_vector = _alloc.allocate(_capacity);
				for (size_type i = 0; i < n; i++) {
					_alloc.construct(_vector + i, val);
				}
			}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true) : _alloc(alloc), _size(std::distance(first, last)), _capacity(_size) {
				_vector = _alloc.allocate(_capacity);
				for (size_type i = 0; first != last; i++) {
					_alloc.construct(_vector + i, *(first++));
				}
			}

			vector (const vector& x) : _alloc(x.alloc), _capacity(0), _size(0), _vector(NULL) {
				*this = x;
			}

			~vector() {
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_vector + i);
				_alloc.deallocate(_vector, _capacity);

			}

			vector& operator= (const vector& x) {
				if (this == &x)
					return (*this);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_vector + i);
				_alloc.deallocate(_vector, _capacity);
				this->_capacity = x._capacity;
				this->_size = x._size;
				this->_vector = x.vector;
				return (*this);
			}

			iterator begin() {
				return (_vector);
			}

			const_iterator begin() const {
				return (_vector);
			}

			reverse_iterator rbegin() {
				return (end());
			}

			const_reverse_iterator rbegin() const {
				return (end());
			}

			iterator end() {
				return (_vector + _size);
			}

			const_iterator end() const {
				return (_vector + _size);
			}

			reverse_iterator rend() {
				return (begin());
			}

			const_reverse_iterator rend() const {
				return (begin());
			}

			size_type size() const {
				return (_size);
			}

			size_type max_size() const {
				return (_alloc.max_size());
			}

			size_type capacity() const {
				return (_capacity);
			}

			bool empty() const {
				return (_size == 0);
			}

			void reserve (size_type n) {
				if (n > max_size())
					throw(std::length_error("OHHH"));
				if (n > _capacity) {
					pointer vect = _alloc.allocate(n);
					for (size_type i = 0; i < _size; i++) {
						_alloc.construct(vect + i, _vector[i]);
						_alloc.destroy(_vector + i);
					}
					_alloc.deallocate(_vector, _capacity);
					_vector = vect;
					_capacity = n;
				}
			}

			void resize (size_type n, value_type val = value_type()) {
				if (n < _size) {
					for (size_type i = n; i < _size; i++)
						_alloc.destroy(_vector + i);
					_size = n;
				}
				else if (n > _size) {
					reserve(n);
					while (_size < _capacity) {
						_alloc.construct(_vector + _size, val);
						_size++;
					}
				}
			}
			
			reference operator[] (size_type n) {

			}
			
			const_reference operator[] (size_type n) const {

			}

		private:

			allocator_type	_alloc;
			size_type		_capacity;
			size_type		_size;
			pointer			_vector;
	};
}

#endif