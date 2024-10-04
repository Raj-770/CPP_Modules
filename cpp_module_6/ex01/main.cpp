/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:45:40 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/11 14:45:54 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
	// Create an instance of Data
	Data myData = {1, 100.5, "Example"};

	// Serialize the data
	uintptr_t serializedData = Serializer::serialize(&myData);
	std::cout << "Serialized data: " << serializedData << std::endl;

	// Deserialize the data
	Data* deserializedData = Serializer::deserialize(serializedData);
	std::cout << "Deserialized data pointer: " << deserializedData << std::endl;

	// Validate that the deserialized data is the same as the original
	if (deserializedData == &myData) {
		std::cout << "Success: Deserialized data is equal to the original data pointer." << std::endl;
	} else {
		std::cout << "Error: Deserialized data is not equal to the original data pointer." << std::endl;
	}

	return 0;
}