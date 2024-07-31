/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:35:07 by rpambhar          #+#    #+#             */
/*   Updated: 2024/07/31 17:06:44 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
	PhoneBook phoneBook;
	std::string command;

	while (true) {

		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "EXIT") {
			std::cout << "Thank you for using the phone book. Byee!" << std::endl;
			break;
		} else if (command == "ADD") {
			phoneBook.addContact();
		} else if (command == "SEARCH") {
			phoneBook.searchContact();
		} else {
			std::cout << "Invalid Command!" << std::endl;
		}
	}

	return (0);
}