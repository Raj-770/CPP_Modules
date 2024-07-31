/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:35:07 by rpambhar          #+#    #+#             */
/*   Updated: 2024/07/31 15:06:37 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
    PhoneBook phoneBook;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {

        std::cout << "Adding a new contact." << std::endl;
        phoneBook.addContact();

        std::cout << "Would you like to add another contact? (y/n): ";
        std::cin >> choice;

        // Clear the input buffer to avoid skipping input after a non-integer input.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }


    return 0;
}