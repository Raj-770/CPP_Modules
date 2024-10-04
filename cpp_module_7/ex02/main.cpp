/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:49:07 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/11 17:56:00 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main() {
	try {
		Array<int> intArray(5);
		for (unsigned int i = 0; i < intArray.size(); ++i) {
			intArray[i] = i * 10;
			std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
		}
		std::cout << std::endl;

		// Test copy
		Array<int> copiedArray = intArray;
		copiedArray[1] = 999; // Modify copy
		std::cout << "Original array after modifying copy: " << std::endl;
		for (unsigned int i = 0; i < intArray.size(); ++i) {
			std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
		}
		std::cout << std::endl;

		std::cout << "Copied array: " << std::endl;
		for (unsigned int i = 0; i < copiedArray.size(); ++i) {
			std::cout << "copiedArray[" << i << "] = " << copiedArray[i] << std::endl;
		}
		std::cout << std::endl;

		// Test out of bounds
		std::cout << intArray[10] << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}