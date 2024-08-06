/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:42:26 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/06 16:47:20 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongAnimal::operator=(const WrongCat& other) {
	WrongAnimal::operator=(other);
	std::cout << "WrongCat assignment operator called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound(void) const {
	std::cout << "Quack Quack!" << std::endl;
}
