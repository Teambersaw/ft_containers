/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:24:35 by jrossett          #+#    #+#             */
/*   Updated: 2023/03/01 14:48:01 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "../pair.hpp"

template < class T1, class T2>
bool comp(const ft::pair<T1, T2> &x, const ft::pair<T1, T2> &y) {
	return (x.first < y.first);
}

#endif