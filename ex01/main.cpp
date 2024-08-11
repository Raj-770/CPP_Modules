/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:58:55 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/11 17:08:18 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	std::string stringArray[] = {"one", "two", "three", "four", "five"};

	std::cout << "Original int array" << std::endl;
	iter(intArray, 5, printElement);
	std::cout << std::endl << std::endl;

	std::cout << "Incrementing int array" << std::endl;
	iter(intArray, 5, increment);
	std::cout << std::endl;

	std::cout << "Modified int array" << std::endl;
	iter(intArray, 5, printElement);
	std::cout << std::endl << std::endl;

	std::cout << "Printing string array" << std::endl;
	iter(stringArray, 5, printElement);
	std::cout << std::endl;

	// iter(stringArray, 5, increment);
}