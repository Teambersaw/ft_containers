/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:40:11 by jrossett          #+#    #+#             */
/*   Updated: 2023/02/28 16:40:13 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:

			typedef Container								container_type;
			typedef typename Container::value_type			value_type;
			typedef typename Container::reference			reference;
			typedef typename Container::const_reference		const_reference;
			typedef typename Container::size_type			size_type;

			explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}

			virtual ~stack() {}

			stack& operator=( const stack& other ) {
				c = other.c;
			}

			bool empty() const {
				return (c.empty());
			}

			size_type size() const {
				return (c.size());
			}

			reference top() {
				return (c.back());
			}

			const_reference top() const {
				return (c.back());
			}

			void push (const value_type& val) {
				c.push_back(val);
			}

			void pop() {
				c.pop_back();
			}

			template <class A, class B>
			friend bool operator== (const ft::stack<A, B>& lhs, const ft::stack<A, B>& rhs);

			template <class A, class B>
			friend bool operator!= (const ft::stack<A, B>& lhs, const ft::stack<A, B>& rhs);

			template <class A, class B>
			friend bool operator< (const ft::stack<A, B>& lhs, const ft::stack<A, B>& rhs);

			template <class A, class B>
			friend bool operator<= (const ft::stack<A, B>& lhs, const ft::stack<A, B>& rhs);

			template <class A, class B>
			friend bool operator> (const ft::stack<A, B>& lhs, const ft::stack<A, B>& rhs);

			template <class A, class B>
			friend bool operator>= (const ft::stack<A, B>& lhs, const ft::stack<A, B>& rhs);

		protected:

			container_type	c;
	};

	template <class A, class B>
	bool operator== (const ft::stack<A, B>& lhs, const ft::stack<A, B>& rhs) {
		return (lhs.c == rhs.c);
	}

	template <class A, class B>
	bool operator!= (const ft::stack<A, B>& lhs, const ft::stack<A, B>& rhs) {
		return (lhs.c != rhs.c);
	}

	template <class A, class B>
	bool operator< (const ft::stack<A, B>& lhs, const ft::stack<A, B>& rhs) {
		return (lhs.c < rhs.c);
	}

	template <class A, class B>
	bool operator<= (const ft::stack<A, B>& lhs, const ft::stack<A, B>& rhs) {
		return (lhs.c <= rhs.c);
	}

	template <class A, class B>
	bool operator> (const stack<A, B>& lhs, const stack<A, B>& rhs) {
		return (lhs.c > rhs.c);
	}

	template <class A, class B>
	bool operator>= (const stack<A, B>& lhs, const stack<A, B>& rhs) {
		return (lhs.c >= rhs.c);
	}
}

#endif