/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:40:45 by rpambhar          #+#    #+#             */
/*   Updated: 2024/07/31 17:07:28 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class PhoneBook
{
	private:
		int numberOfContacts;
		Contact contacts[8];

		// Helper Methods
		std::string turncateString(const std::string& str) const;

	public:
		PhoneBook();
		void addContact();
		void searchContact() const;
};

#endif