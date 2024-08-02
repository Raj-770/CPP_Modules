/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:23:57 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/02 17:51:46 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main() {
	Point a(0, 0);
	Point b(1, 0);
	Point c(0, 1);
	Point inside(0.1f, 0.1f);
	Point outside(1, 1);
	Point edge(0.5, 0);

	std::cout << "Inside should be true: " << bsp(a, b, c, inside) << std::endl;
	std::cout << "Outside should be false: " << bsp(a, b, c, outside) << std::endl;
	std::cout << "Edge should be false: " << bsp(a, b, c, edge) << std::endl;

	return 0;
}