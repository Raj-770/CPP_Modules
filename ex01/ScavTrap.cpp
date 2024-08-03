/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:17:52 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/03 15:18:15 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

// Constructor
ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " constructed." << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &source)
	: ClapTrap(source) {
	std::cout << "ScavTrap " << this->name << " copied." << std::endl;
}

// Copy assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &source) {
	if (this != &source) {
		ClapTrap::operator=(source);
	}
	std::cout << "ScavTrap " << this->name << " assigned." << std::endl;
	return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " destroyed." << std::endl;
}

// Overridden attack method
void ScavTrap::attack(const std::string &target) {
	if (hitPoints > 0 && energyPoints > 0) {
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "ScavTrap " << name << " cannot attack due to low energy or hit points!" << std::endl;
	}
}

// guardGate method
void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}