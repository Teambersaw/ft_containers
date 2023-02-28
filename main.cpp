/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:39:23 by jrossett          #+#    #+#             */
/*   Updated: 2023/02/28 16:44:33 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "surcharge.hpp"
#include <iostream>

using namespace ft;

int main() {
	vector<int> vect(4, 10);
	vect.push_back(4);
	std::cout << vect << std::endl;
	return (0);
}
