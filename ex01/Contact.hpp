/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:00:16 by rpambhar          #+#    #+#             */
/*   Updated: 2024/07/31 14:38:02 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

/* const in the getter method declaration tells the compiler and
other programmers that this member function does not modify the
state of the object on which it is called. */

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		Contact(const std::string &firstName, const std::string &lastName, const std::string &nickName, const std::string &phoneNumber, const std::string &darkestSecret);

		std::string getFirstName() const;
		void setFirstName(const std::string &firstName);

		std::string getLastName() const;
		void setLastName(const std::string &lastName);

		std::string getNickName() const;
		void setNickName(const std::string &nickName);

		std::string getPhoneNumber() const;
		void setPhoneNumber(const std::string &phoneNumber);

		std::string getDarkestSecret() const;
		void setDarkestSecret(const std::string &darkestSecret);
};

#endif