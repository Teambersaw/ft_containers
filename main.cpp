/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:39:23 by jrossett          #+#    #+#             */
/*   Updated: 2023/03/16 14:18:04 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "surcharge.hpp"

using namespace ft;

int main() {
	vector<int> vect(4, 10);
	vect.push_back(4);
	std::cout << vect << std::endl;
	return (0);
}
