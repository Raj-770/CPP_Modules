/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:56:02 by rpambhar          #+#    #+#             */
/*   Updated: 2024/07/31 17:09:09 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->numberOfContacts = 0;

}

void PhoneBook::addContact() {
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << "Enter First Name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, nickName);
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, darkestSecret);

	if (firstName.empty() || lastName.empty() || nickName.empty() || phoneNumber.empty() || darkestSecret.empty()) {
		std::cout << "Error: All fields must be filled." << std::endl;
		return ;
	}

	int index = numberOfContacts % 8;
	contacts[index].setFirstName(firstName);
	contacts[index].setLastName(lastName);
	contacts[index].setNickName(nickName);
	contacts[index].setPhoneNumber(phoneNumber);
	contacts[index].setDarkestSecret(darkestSecret);

	if (numberOfContacts < 8)
		numberOfContacts++;
}

std::string PhoneBook::turncateString(const std::string& str) const {
	if (str.length() > 9)
		return str.substr(0, 9) + '.';
	return str;
}

void PhoneBook::searchContact() const {
	std::cout	<< std::right;
	std::cout	<< std::setw(10) << "Index" << " | "
				<< std::setw(10) << "First Name" << " | "
				<< std::setw(10) << "Last Name" << " | "
				<< std::setw(10) << "Nickname" << " | " << std::endl;

	for (int i = 0; i < numberOfContacts; i++) {
		std::cout	<< std::setw(10) << (i + 1) << " | "
					<< std::setw(10) << turncateString(contacts[i].getFirstName()) << " | "
					<< std::setw(10) << turncateString(contacts[i].getLastName()) << " | "
					<< std::setw(10) << turncateString(contacts[i].getNickName()) << " | " << std::endl;
	}

	int index;
	std::string input;
	std::cout << "Enter the index of the contact to view: ";
	 std::getline(std::cin, input);

	// Use a string stream to parse the integer from the input
	// If the input can be parsed into an integer (iss >> index)
	// If the entire input string was consumed to ensure no extra characters were input (!iss.eof())
	std::istringstream iss(input);
	if (!(iss >> index) || !iss.eof()) {
		std::cout << "Invalid index. Please enter a numeric index." << std::endl;
		return;
	}

	index--;

	if (index < 0 || index >= numberOfContacts) {
		std::cout << "Invalid index. Please try again." << std::endl;
		return ;
	}

	Contact contact = contacts[index];
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nick Name: " << contact.getNickName() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}