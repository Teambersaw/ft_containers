#ifndef TREE_ITER_HPP
# define TREE_ITER_HPP

#include "iterator.hpp"
#include "RBT.hpp"

namespace ft
{

	template <class T>
	class RBiter: public ft::iterator_traits<T*>
	{
		public:

			typedef ft::bidirectional_iterator_tag iterator_category;
			typedef typename ft::iterator_traits<T*>::value_type value_type;
			typedef typename ft::iterator_traits<T*>::reference reference;
			typedef typename ft::iterator_traits<T*>::pointer pointer;
			typedef typename ft::iterator_traits<T*>::difference_type difference_type;
			typedef Node<value_type>* Nodes;

			RBiter() : _it() {}
			RBiter(Nodes it) : _it(it) {}

			RBiter(const RBiter<value_type> &x) : _it(x.base()) {}

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
				if (is_nill(_it))
					return (*this);
				if (!is_nill(_it->right))
				{
					_it = _it->right;
					while (!is_nill(_it->left))
						_it = _it->left;
				}
				else if (!is_nill(_it->parent))
				{
					Nodes tmp = _it->parent;
					while (!is_nill(tmp) && tmp->right == _it)
					{
						_it = tmp;
						tmp = tmp->parent;
					}
					_it = tmp;
				}
				else
					_it = _it->right;
				return (*this);
			}

			RBiter operator++(int) {
				RBiter tmp = *this;
				++(*this);
				return tmp;
			}

			RBiter& operator--()
			{
				if (is_nill(_it))
				{
					std::cout << "oui\n";
					_it = maximum(_it->parent);
					return (*this);
				}
				if (!is_nill(_it->left))
				{
					_it = _it->left;
					while (!is_nill(_it->right))
						_it = _it->right;
				}
				else if (!is_nill(_it->parent))
				{
					Nodes tmp = _it->parent;
					while (!is_nill(tmp) && tmp->left == _it)
					{
						_it = tmp;
						tmp = tmp->parent;
					}
					_it = tmp;
				}
				else
					_it = _it->left;
				return (*this);
			}

			RBiter operator--(int) {
				RBiter tmp = *this;
				--(*this);
				return tmp;
			}

			Nodes	base() const {
				return (_it);
			}

		private:

			Nodes maximum(Nodes node) const
			{
				Nodes tmp = node;

				while (!is_nill(tmp) && !is_nill(tmp->right))
					tmp = tmp->right;
				return (tmp);
			}

			bool is_nill(Nodes it) const {
				if (it->left == NULL && it->right == NULL)
					return (1);
				return (0);
			}

			Nodes	_it;
	};

	template <class T>
	class CRBiter: public ft::iterator_traits<const T*>
	{
		public:

			typedef ft::bidirectional_iterator_tag iterator_category;
			typedef typename ft::iterator_traits<const T*>::value_type value_type;
			typedef typename ft::iterator_traits<const T*>::reference reference;
			typedef typename ft::iterator_traits<const T*>::pointer pointer;
			typedef typename ft::iterator_traits<const T*>::difference_type difference_type;
			typedef Node<value_type>* Nodes;

			CRBiter() : _it() {}
			CRBiter(Nodes it) : _it(it) {}

			CRBiter(const RBiter<value_type> &x) : _it(x.base()) {}
			CRBiter(const CRBiter<value_type> &x) : _it(x.base()) {}

			CRBiter &operator=(const CRBiter<value_type> &x) {
				if (this == &x)
					return (*this);
				_it = x.base();
				return (*this);
			}

			~CRBiter() {}

			reference	const operator*() const {
				return (_it->value);
			}

			pointer operator->() const {
				return (&_it->value);
			}

			CRBiter& operator++()
			{
				if (is_nill(_it))
					return (*this);
				if (!is_nill(_it->right))
				{
					_it = _it->right;
					while (!is_nill(_it->left))
						_it = _it->left;
				}
				else if (!is_nill(_it->parent))
				{
					Nodes tmp = _it->parent;
					while (!is_nill(tmp) && tmp->right == _it)
					{
						_it = tmp;
						tmp = tmp->parent;
					}
					_it = tmp;
				}
				else
					_it = _it->right;
				return (*this);
			}

			CRBiter operator++(int) {
				CRBiter tmp = *this;
				++(*this);
				return tmp;
			}

			CRBiter& operator--()
			{
				if (is_nill(_it))
				{
					_it = maximum(_it->parent);
					_it = _it->parent;
					return (*this);
				}
				if (!is_nill(_it->left))
				{
					_it = _it->left;
					while (!is_nill(_it->right))
						_it = _it->right;
				}
				else if (!is_nill(_it->parent))
				{
					Nodes tmp = _it->parent;
					while (!is_nill(tmp) && tmp->left == _it)
					{
						_it = tmp;
						tmp = tmp->parent;
					}
					_it = tmp;
				}
				else
					_it = _it->left;
				return (*this);
			}

			CRBiter operator--(int) {
				CRBiter tmp = *this;
				--(*this);
				return tmp;
			}

			Nodes	base() const {
				return (_it);
			}

		private:

			Nodes maximum(Nodes node) const
			{
				Nodes tmp = node;

				while (!is_nill(tmp) && !is_nill(tmp->right))
					tmp = tmp->right;
				return (tmp);
			}

			bool is_nill(Nodes it) const {
				if (it->left == NULL && it->right == NULL)
					return (1);
				return (0);
			}

			Nodes	_it;
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

	template<class A, class B>
	bool operator==(const RBiter<A> &lhs, const CRBiter<B> &rhs) {
		return (lhs.base() == rhs.base());
	}

	template<class A, class B>
	bool operator!=(const CRBiter<A> &lhs, const RBiter<B> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<class A, class B>
	bool operator==(const CRBiter<A> &lhs, const RBiter<B> &rhs) {
		return (lhs.base() == rhs.base());
	}

	template<class A, class B>
	bool operator!=(const RBiter<A> &lhs, const CRBiter<B> &rhs) {
		return (lhs.base() != rhs.base());
	}

}

#endif