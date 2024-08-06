/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:06:04 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/06 16:50:30 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default Constructor
Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
}

// Constrcutor with parmeter type
Animal::Animal(std::string type): type(type) {
	std::cout << "Animal constructor with parameter called" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

// Assignment Operator
Animal &Animal::operator=(const Animal& other) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

// Destructor
Animal::~Animal () {
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType(void) const {
	return (type);
}

void Animal::makeSound(void) const {
	std::cout << "Oink Oink!" << std::endl;
}