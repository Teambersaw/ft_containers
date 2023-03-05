#ifndef TREE_ITER_HPP
# define TREE_ITER_HPP

#include "../iterator.hpp"
#include "RBT.hpp"

namespace ft
{

	template <class T>
	class iterator
	{
		public:

			typedef ptrdiff_t							difference_type;
			typedef T									value_type;
			typedef T*									pointer;
			typedef T&									reference;
			typedef Node<value_type>*					Node;
			typedef ft::bidirectional_iterator_tag		iterator_category;


			iterator() : _it() {}
			iterator(Node it) : _it(it) {}

			iterator(const iterator<value_type> &x) {
				*this = x;
			}

			iterator &operator=(const iterator<value_type> &x) {
				if (this == &x)
					return (*this);
				_it = x.base();
				return (*this);
			}

			~iterator() {}

			bool operator==(const iterator &x) const {
				return (_it == x.base());
			}

			bool operator!=(const iterator &x) const {
				return (_it != x.base());
			}

			reference	operator*() const {
				return (_it->value);
			}

			pointer operator->() const {
				return (&_it->value);
			}

			iterator& operator++()
			{
				
				return (*this);
			}

			iterator operator++(int) {
				iterator tmp = *this;
				++(*this);
				return tmp;
			}

			iterator& operator--()
			{
				
				return (*this);
			}

			iterator operator--(int) {
				iterator tmp = *this;
				--(*this);
				return tmp;
			}

			Node	base() const {
				return (_it);
			}

		private:

			Node	_it;
	};

}

#endif