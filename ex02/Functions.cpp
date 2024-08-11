/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:03:55 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/11 15:28:53 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include <iostream>
#include <cstdlib>

Base* generate(void) {
	int i = std::rand() % 3;
	switch (i) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			return NULL;
	}
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (const std::bad_cast&) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (const std::bad_cast&) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (const std::bad_cast&) {}
}
