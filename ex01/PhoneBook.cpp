/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:56:02 by rpambhar          #+#    #+#             */
/*   Updated: 2024/07/31 15:46:32 by rpambhar         ###   ########.fr       */
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
	std::cin >> firstName;
	std::cout << "Enter Last Name: ";
	std::cin >> lastName;
	std::cout << "Enter Nickname: ";
	std::cin >> nickName;
	std::cout << "Enter Phone Number: ";
	std::cin >> phoneNumber;
	std::cout << "Enter Darkest Secret: ";
	std::cin >> darkestSecret;

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