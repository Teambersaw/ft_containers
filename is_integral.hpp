/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:12:35 by jrossett          #+#    #+#             */
/*   Updated: 2023/02/28 16:39:02 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft
{

	template<class T, bool v>
	struct integral_constant {
		static const bool value = v;
		typedef T value_type;
		typedef integral_constant type;
		operator value_type() const { return value; }
	};

	template <class T>
	struct is_integral : public ft::integral_constant<T, false> {};

	template <>
	struct is_integral<bool> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<char> : public ft::integral_constant<char, true> {};

	template <>
	struct is_integral<wchar_t> : public ft::integral_constant<wchar_t, true> {};

	template <>
	struct is_integral<signed char> : public ft::integral_constant<signed char, true> {};

	template <>
	struct is_integral<short int> : public ft::integral_constant<short int, true> {};

	template <>
	struct is_integral<int> : public ft::integral_constant<int, true> {};

	template <>
	struct is_integral<long int> : public ft::integral_constant<long int, true> {};

	template <>
	struct is_integral<long long int> : public ft::integral_constant<long long int, true> {};

	template <>
	struct is_integral<unsigned char> : public ft::integral_constant<unsigned char, true> {};

	template <>
	struct is_integral<unsigned short int> : public ft::integral_constant<unsigned short int, true> {};

	template <>
	struct is_integral<unsigned int> : public ft::integral_constant<unsigned int, true> {};

	template <>
	struct is_integral<unsigned long int> : public ft::integral_constant<unsigned long int, true> {};

	template <>
	struct is_integral<unsigned long long int> : public ft::integral_constant<unsigned long long int, true> {};

	template <bool Cond, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if<true, T> { typedef T type; };
}

#endif