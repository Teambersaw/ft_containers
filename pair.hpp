/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:39:23 by jrossett          #+#    #+#             */
/*   Updated: 2023/02/28 16:40:04 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template< class T1, class T2 >
	struct pair
	{

		typedef T1	first_type;
		typedef T2	second_type;

		pair() : first(first_type()), second(second_type()) {}

		pair (const first_type& a, const second_type& b) : first(a), second(b) {}

		template <class U, class V>
		pair (const pair<U,V>& pr) : first(pr.first), second(pr.second){}

		pair& operator=(const pair& pr) {
			if (this == &pr)
				return (*this);
			this->first = pr.first;
			this->second = pr.second;
			return (*this);
		}

		bool operator==( const pair<T1, T2>& rhs) {
			return (this->first == rhs.first && this->second == rhs.second);
		}

		bool operator!=( const pair<T1, T2>& rhs) {
			return (!(this->first == rhs.first && this->second == rhs.second));
		}

		bool operator<( const pair<T1, T2>& rhs) {
			if (this->first == rhs.first)
				return (this->second < rhs.second);
			return (this->first < rhs.first);
		}

		bool operator<=( const pair<T1, T2>& rhs) {
			if (this->first == rhs.first)
				return (this->second <= rhs.second);
			return (this->first <= rhs.first);
		}

		bool operator>( const pair<T1, T2>& rhs) {
			if (this->first == rhs.first)
				return (this->second > rhs.second);
			return (this->first > rhs.first);
		}

		bool operator>=( const pair<T1, T2>& rhs) {
			if (this->first == rhs.first)
				return (this->second >= rhs.second);
			return (this->first >= rhs.first);
		}

		first_type first;
		second_type second;
	};

	template < class T1, class T2 >
	pair<T1,T2> make_pair (T1 x, T2 y) {
		return (pair<T1,T2>(x, y));
	}
}

#endif