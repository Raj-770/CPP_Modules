/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:14:11 by rpambhar          #+#    #+#             */
/*   Updated: 2024/07/31 14:38:34 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructor
Contact::Contact(const std::string &firstName, const std::string &lastName, const std::string &nickName, const std::string &phoneNumber, const std::string &darkestSecret): firstName(firstName), lastName(lastName), nickName(nickName), phoneNumber(phoneNumber), darkestSecret(darkestSecret) {}

// Getters
std::string Contact::getFirstName() const {
	return (firstName);
}

std::string Contact::getLastName() const {
	return (lastName);
}

std::string Contact::getNickName() const {
	return (nickName);
}

std::string Contact::getPhoneNumber() const {
	return (phoneNumber);
}

std::string Contact::getDarkestSecret() const {
	return (darkestSecret);
}

// Setter
void Contact::setFirstName(const std::string &firstName) {
	this->firstName = firstName;
}

void Contact::setLastName(const std::string &lastName) {
	this->lastName = lastName;
}

void Contact::setNickName(const std::string &nickName) {
	this->nickName = nickName;
}

void Contact::setPhoneNumber(const std::string &phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret) {
	this->darkestSecret = darkestSecret;
}
