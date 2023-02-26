/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:47:02 by jrossett          #+#    #+#             */
/*   Updated: 2023/02/24 13:46:28 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include <iterator>
# include "iterator.hpp"
# include "is_integral.hpp"
# include "equal.hpp"
# include <iostream>


namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:

			typedef T															value_type;
			typedef Alloc														allocator_type;
			typedef std::size_t													size_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef pointer														iterator;
			typedef const_pointer												const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type			difference_type;

			explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _size(0), _vector(NULL) {}

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(n), _size(n) {
				_vector = _alloc.allocate(_capacity);
				for (size_type i = 0; i < n; i++) {
					_alloc.construct(_vector + i, val);
				}
			}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true) {
				_alloc = alloc;
				_size = std::distance(first, last);
				_capacity = _size;
				_vector = _alloc.allocate(_capacity);
				for (size_type i = 0; first != last; i++) {
					_alloc.construct(_vector + i, *(first++));
				}
			}

			vector (const vector& x) : _alloc(x._alloc), _capacity(0), _size(0), _vector(NULL) {
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
				_vector = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++) {
					_alloc.construct(_vector + i, x[i]);
				}
				return (*this);
			}

			iterator begin() {
				return (_vector);
			}

			const_iterator begin() const {
				return (_vector);
			}

			reverse_iterator rbegin() {
				return ((reverse_iterator) end());
			}

			const_reverse_iterator rbegin() const {
				return ((const_reverse_iterator) end());
			}

			iterator end() {
				return (_vector + _size);
			}

			const_iterator end() const {
				return (_vector + _size);
			}

			reverse_iterator rend() {
				return ((reverse_iterator) begin());
			}

			const_reverse_iterator rend() const {
				return ((const_reverse_iterator) begin());
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
				if (n <= _capacity)
					return ;
				if (n > max_size())
					throw(std::length_error("vector::reserve"));
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
					while (_size < n) {
						_alloc.construct(_vector + _size, val);
						_size++;
					}
				}
			}

			reference operator[] (size_type n) {
				return (_vector[n]);
			}
			
			const_reference operator[] (size_type n) const {
				return (_vector[n]);
			}

			void push_back (const value_type& val) {
				if (_size == _capacity) {
					if (_capacity == 0)
						reserve(1);
					else
						reserve(_capacity * 2);
					_alloc.construct(_vector + _size, val);
				}
				else
					_alloc.construct(_vector + _size, val);
				_size++;
				std::cout << "issou" << std::endl;
			}

			void pop_back () {
				_alloc.destroy(_vector + _size - 1);
				_size--;
			}

			reference at (size_type n) {
				if (n >= _size)
					throw(std::out_of_range("at error: out of range"));
				return (_vector[n]);
			}

			const_reference at (size_type n) const {
				if (n >= _size)
					throw(std::out_of_range("at error: out of range"));
				return (_vector[n]);
			}

			reference front() {
				return (*_vector);
			}

			const_reference front() const {
				return (*_vector);
			}

			reference back() {
				return (*(_vector + _size - 1));
			}

			const_reference back() const {
				return (*(_vector + _size - 1));
			}

			allocator_type get_allocator() const {
				return (_alloc);
			}

			void clear() {
				while (_size != 0) {
					_alloc.destroy(_vector + --_size);
				}
			}

			void swap (vector& x) {
				size_type tmp = x._capacity;
				x._capacity = _capacity;
				_capacity = tmp;

				tmp = x._size;
				x._size = _size;
				_size = tmp;

				pointer tmp2 = x._vector;
				x._vector = _vector;
				_vector = tmp2;
			}

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true) {
				this->clear();
				size_type tmp = std::distance(first, last);
				if (_capacity < tmp) {
					reserve(tmp);
				}
				_size = tmp;
				for (size_type i = 0; first != last; i++)
					_alloc.construct(_vector + i, *(first++));
			}

			void assign (size_type n, const value_type& val) {
				this->clear();
				if (n > _capacity)
					reserve(n);
				_size = n;
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(_vector + i, val);
			}

			void insert (iterator pos, size_type n, const value_type& val)
			{
				size_type nb_begin = std::distance(begin(), pos);
				size_type dist = std::distance(pos, end());
				size_type old_capacity = _capacity;

				if (!n)
					return ;
				if (_capacity < _size + n)
				{
					if (_size + n > _capacity * 2)
						_capacity = _size + n;
					else if (n + _size > _capacity)
						_capacity = _capacity * 2;
					pointer tmp = _alloc.allocate(_capacity);
					for (size_type i = 0; i < nb_begin; i++)
						_alloc.construct(tmp + i, _vector[i]);
					for (size_type i = nb_begin; i < n + nb_begin; i++)
						_alloc.construct(tmp + i, val);
					for (size_type i = nb_begin + n; i < _size + n; i++)
						_alloc.construct(tmp + i, _vector[nb_begin++]);
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(_vector + i);
					_alloc.deallocate(_vector, old_capacity);
					_vector = tmp;
				}
				else
				{
					for (size_type i = 0; i < dist; i++)
					{
						_alloc.construct(_vector + n + _size - i - 1, _vector[_size - i - 1]);
						_alloc.destroy(_vector + (nb_begin + i - 1));
					}
					for (size_type i = 0; i < n; i++)
						_alloc.construct(_vector + (nb_begin + i), val);
				}
				_size += n;
			}

			iterator insert (iterator position, const value_type& val) {
				size_type pos = std::distance(begin(), position);
				insert(position, 1, val);
				return (begin() + pos);
			}

			template <class InputIterator>
			void insert (iterator pos, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
			{
				size_type n = std::distance(first, last);
				size_type nb_begin = std::distance(begin(), pos);
				size_type dist = std::distance(pos, end());
				size_type old_capacity = _capacity;

				if (!n)
					return ;
				if (_capacity < _size + n)
				{
					if (_size + n > _capacity * 2)
						_capacity = _size + n;
					else if (n + _size > _capacity)
						_capacity = _capacity * 2;
					pointer tmp = _alloc.allocate(_capacity);
					for (size_type i = 0; i < nb_begin; i++)
						_alloc.construct(tmp + i, _vector[i]);
					for (size_type i = nb_begin; i < n + nb_begin; i++)
						_alloc.construct(tmp + i, *(first++));
					for (size_type i = nb_begin + n; i < _size + n; i++)
						_alloc.construct(tmp + i, _vector[nb_begin++]);
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(_vector + i);
					_alloc.deallocate(_vector, old_capacity);
					_vector = tmp;
				}
				else
				{
					for (size_type i = 0; i < dist; i++)
					{
						_alloc.construct(_vector + n + _size - i - 1, _vector[_size - i - 1]);
						_alloc.destroy(_vector + (nb_begin + i - 1));
					}
					for (size_type i = 0; i < n; i++)
						_alloc.construct(_vector + (nb_begin + i), *(first++));
				}
				_size += n;
			}

			iterator erase (iterator pos) {
				size_type n = std::distance(begin(), pos);
				_alloc.destroy(pos);
				for (size_type i = n; i < _size - 1; i++)
				{
					_alloc.construct(_vector + i, *(_vector + i + 1));
					 _alloc.destroy(_vector + i + 1);
				}
				_size--;
				return (pos);
			}

			iterator erase (iterator first, iterator last) {
				size_type n = std::distance(first, last);
				size_type nb_end = std::distance(last, end());
				iterator it = first;
				if (first == last)
					return (last);
				for (size_type i = 0; i < n; i++) {
					_alloc.destroy(it);
					it++;
				}
				for (size_type i = 0; i < nb_end; i++) {
					_alloc.construct( _vector + (_size - nb_end - n + i), *(_vector + _size - nb_end + i));
					_alloc.destroy(_vector + _size - nb_end + i);
				}
				_size -= n;
				return (first);
			}

		private:

			allocator_type	_alloc;
			size_type		_capacity;
			size_type		_size;
			pointer			_vector;
	};

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		for (size_t i = 0; i < lhs.size(); i++) {
			if (lhs[i] != rhs[i])
				return (false);
		}
		return (true);
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	}
}

#endif