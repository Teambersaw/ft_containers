/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:39:45 by jrossett          #+#    #+#             */
/*   Updated: 2023/02/28 16:44:54 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "surcharge.hpp"

using namespace std;

int main() {
	vector<int> vect(4, 10);
	vect.push_back(4);
	std::cout << vect << std::endl;
	return (0);
}
