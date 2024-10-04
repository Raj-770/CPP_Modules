/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:13:44 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/11 15:27:02 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	std::srand(time(NULL));

	Base* obj = generate();

	if (obj == NULL) {
		std::cout << "Error generating object" << std::endl;
		return 1;
	}
	std::cout << "Identify by pointer: ";
	identify(obj);


	std::cout << "Identify by reference: ";
	identify(*obj);


	delete obj;
	return 0;
}
