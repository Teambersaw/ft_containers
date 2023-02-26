/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surcharge.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:40:22 by jrossett          #+#    #+#             */
/*   Updated: 2023/02/24 10:27:22 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SURCHARGE_HPP
# define SURCHARGE_HPP

# include <iostream>

	template<class T>
	std::ostream &operator<<(std::ostream &stream, NS::vector<T> const &v)
	{
		typename NS::vector<T>::const_iterator it;

		stream << "[";
		for (it = v.begin(); it != v.end(); it++)
			stream << *it << (it + 1 == v.end() ? "" : ", ");
		stream << "]\n";
		stream << "size of Vct: " << v.size() << "\nCapacity of vct: " << v.capacity() << std::endl;
		return (stream);
	}

#endif