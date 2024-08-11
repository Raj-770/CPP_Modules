/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:03:55 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/11 15:12:27 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.cpp"
#include <iostream>
#include <cstdlib>

Base* generate(void) {
	switch (std::rand % 3) {
		case 1:
			return new A;
		case 2:
			return new B;
		case 3:
			return new C;
		default
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

void identify(Base &p) {
	try {
		if (dynamic_cast<A&>(p))
			std::cout << "A" << std::endl;
	} catch (std::bad_cast&) {
		try {
			if (dynamic_cast<B&>(p))
				std::cout << "B" << std::endl;
		} catch (std::bad_cast&) {
			try {
				if (dynamic_cast<C&>(p))
					std::cout << "C" << std::endl;
			} catch (std::bad_cast&) {
			}
		}
	}
}
