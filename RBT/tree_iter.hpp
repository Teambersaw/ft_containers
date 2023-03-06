#ifndef TREE_ITER_HPP
# define TREE_ITER_HPP

#include "../iterator.hpp"
#include "RBT.hpp"

namespace ft
{

	template <class T>
	class RBiter
	{
		public:

			typedef ptrdiff_t							difference_type;
			typedef T									value_type;
			typedef T*									pointer;
			typedef T&									reference;
			typedef Node<value_type>*					Node;
			typedef ft::bidirectional_iterator_tag		iterator_category;


			RBiter() : _it() {}
			RBiter(Node it) : _it(it) {}

			RBiter(const RBiter<value_type> &x) {
				*this = x;
			}

			RBiter &operator=(const RBiter<value_type> &x) {
				if (this == &x)
					return (*this);
				_it = x.base();
				return (*this);
			}

			~RBiter() {}

			reference	operator*() const {
				return (_it->value);
			}

			pointer operator->() const {
				return (&_it->value);
			}

			RBiter& operator++()
			{
				
				return (*this);
			}

			RBiter operator++(int) {
				RBiter tmp = *this;
				++(*this);
				return tmp;
			}

			RBiter& operator--()
			{
				
				return (*this);
			}

			RBiter operator--(int) {
				RBiter tmp = *this;
				--(*this);
				return tmp;
			}

			Node	base() const {
				return (_it);
			}

		private:

			Node	_it;
	};

	template <class T>
	class CRBiter
	{
		public:

			typedef ptrdiff_t							difference_type;
			typedef const T								value_type;
			typedef const T*							pointer;
			typedef const T&							reference;
			typedef Node<value_type>*					Node;
			typedef ft::bidirectional_iterator_tag		iterator_category;


			CRBiter() : _it() {}
			CRBiter(Node it) : _it(it) {}

			CRBiter(const CRBiter<value_type> &x) {
				*this = x;
			}

			CRBiter &operator=(const CRBiter<value_type> &x) {
				if (this == &x)
					return (*this);
				_it = x.base();
				return (*this);
			}

			~CRBiter() {}

			reference	operator*() const {
				return (_it->value);
			}

			pointer operator->() const {
				return (&_it->value);
			}

			CRBiter& operator++()
			{
				
				return (*this);
			}

			CRBiter operator++(int) {
				CRBiter tmp = *this;
				++(*this);
				return tmp;
			}

			CRBiter& operator--()
			{
				
				return (*this);
			}

			CRBiter operator--(int) {
				CRBiter tmp = *this;
				--(*this);
				return tmp;
			}

			Node	base() const {
				return (_it);
			}

		private:

			Node	_it;
	};

	template<class A, class B>
	bool operator==(const RBiter<A> &lhs, const RBiter<B> &rhs) {
		return (lhs.base() == rhs.base());
	}

	template<class A, class B>
	bool operator!=(const RBiter<A> &lhs, const RBiter<B> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<class A, class B>
	bool operator==(const CRBiter<A> &lhs, const CRBiter<B> &rhs) {
		return (lhs.base() == rhs.base());
	}

	template<class A, class B>
	bool operator!=(const CRBiter<A> &lhs, const CRBiter<B> &rhs) {
		return (lhs.base() != rhs.base());
	}

}

#endif